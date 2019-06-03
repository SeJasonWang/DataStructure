//
//  dynamicprogramming.c
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "dynamicprogramming.h"
#include <stdlib.h>

#define MAX(a, b)    ((a) > (b) ? (a) : (b))

int recursion_knapsackValue(int weight[], int value[], int capacity, int n) { // Θ(2^n)
    
    if (n == 0) {
        return 0;
    }

    if (weight[n-1] > capacity) {
        return recursion_knapsackValue(weight, value, capacity, n-1);
    } else {
        int value1 = value[n-1] + recursion_knapsackValue(weight, value, capacity - weight[n-1], n-1);
        int value2 = recursion_knapsackValue(weight, value, capacity, n-1);
        return MAX(value1, value2);
    }
}

int dynamic_knapsackValue(int weight[], int value[], int capacity, int n) { // Θ(n * capacity)

    int *preResults = malloc(sizeof *(preResults) * (capacity+1));
    int *results = malloc(sizeof *(results) * (capacity+1));
    
    // the first item initialization
    for (int i = 0; i <= capacity; i++) {
        if (i < weight[0]) {
            preResults[i] = 0;
        } else {
            preResults[i] = value[0];
        }
    }
    
    // traverse all items except the first item
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (j < weight[i]) { // current weight is larger than the capacity 'j'
                results[j] = preResults[j];
            } else { // current weight is smaller than the capacity 'j', make a choice
                results[j] = MAX(preResults[j], preResults[j - weight[i]] + value[i]);
            }
        }
        for (int j = 0; j <= capacity; j++) {
            preResults[j] = results[j];
        }
    }
    
    int result = results[capacity];
    
    free(preResults);
    free(results);
    
    return result;
}

int dynamic_subsequence(int value[], int n) {
    
    int *num = malloc(sizeof *(num) * n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        num[i] = 1;
        int pre_max = 0;
        for (int j = 0; j < i; j++) {
            if (value[i] > value[j] & pre_max < value[j]) {
                pre_max = num[j];
            }
        }
        num[i] += pre_max;
        if (num[i] > max) {
            max = num[i];
        }
    }
        
    free(num);
    return max;
}

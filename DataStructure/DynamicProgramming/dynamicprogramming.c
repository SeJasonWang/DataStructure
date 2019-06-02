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

int simple_recursion(int weight[], int value[], int capacity, int n) { // Θ(2^n)
    
    if (n == 0) {
        return 0;
    }

    if (weight[n-1] > capacity) {
        return simple_recursion(weight, value, capacity, n-1);
    } else {
        int value1 = value[n-1] + simple_recursion(weight, value, capacity - weight[n-1], n-1);
        int value2 = simple_recursion(weight, value, capacity, n-1);
        return MAX(value1, value2);
    }
}

int dynamic_programming(int weight[], int value[], int capacity, int n) { // Θ(n * capacity)

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

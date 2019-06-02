//
//  sort.c
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "sort.h"
#include <stdlib.h>

Sort new_sort(int n) {
    Sort newsort;
    
    newsort.data = malloc(sizeof *(newsort.data) * n);
    
    newsort.size = n;
    return newsort;
}

void sort_quicksort_r(int *data, int first, int last, int step) {
    
    // medium of 3 (first, medium and last)
    int medium = (first + last) / 2;
    int index = last;
    int temp = data[last];
    if (data[last] > data[first] && data[last] > data[medium]) {
        if (data[first] > data[medium]) {
            index = first;
            temp = data[first];
        } else if (data[first] < data[medium]) {
            index = medium;
            temp = data[medium];
        }
    } else if (data[last] < data[first] && data[last] < data[medium]) {
        if (data[first] < data[medium]) {
            index = first;
            temp = data[first];
        } else if (data[first] > data[medium]) {
            index = medium;
            temp = data[medium];
        }
    }
    data[index] = data[last];
    data[last] = temp;

    
    // sort
    if (first < last) {
        int i = first;
        int j = last - 1;
        while (i < j) {
            while (i < last && data[i] < data[last]) {
                i++;
            }
            while (j >= first && data[j] > data[last]) {
                j--;
            }
            if (i < j) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        if (data[i] > data[last]) {
            int temp = data[i];
            data[i] = data[last];
            data[last] = temp;
        }
        
        printf("current partitioning step: %d\n", step + 1);
        for (int s = first; s <= last; s++) {
            if (s == i && last - first > 1) printf("|");
            printf("%d", data[s]);
            if (s == i &&  last - first > 1) printf("|");
            if (s != last) {
                printf("->");
            }
        }
        printf("\n\n");
        step++;
        
        sort_quicksort_r(data, first, j, step);
        sort_quicksort_r(data, i+1, last, step);
    }
}

void sort_quicksort(Sort *self) {
    sort_quicksort_r(self->data, 0, self->size - 1, 0);
}

int maxlength(int a[], int len) {
    int bits = 1, p = 10, i;
    for (i = 0; i < len; i++) {
        while (a[i] >= p) {
            p = p * 10;
            bits++;
        }
    }
    return bits;
}

int getdigit(int num, int pos) {
    int temp = 1, i;
    for (i = 0; i < pos - 1; i++) {
        temp = temp * 10;
    }
    return (num / temp) % 10;
}

void sort_radixsort(Sort *self) {
    int *data = self->data;
    int size = self->size;
    int *bucket[10];
    int i;
    for (i = 0; i < 10; i++) {
        bucket[i] = malloc(sizeof(int) * (size + 1));
        bucket[i][0] = 0; // remember the account of numbers at index 0
    }
    int bit; // the max lenght of the data, bit = 1 (the unit)
    for (bit = 1; bit <= maxlength(data, size); bit++) {
        for (i = 0; i < size; i++) {
            int num = getdigit(data[i], bit);
            int index = ++bucket[num][0];
            bucket[num][index] = data[i];
            
        }
        int index = 0;
        for (i = 0; i < 10; i++) {
            int j;
            for (j = 1; j <= bucket[i][0]; j++) {
                data[index++] = bucket[i][j];
            }
            bucket[i][0] = 0;       // reset the accounts of numbers
        }
        
        printf("current pass: %d\n", bit);
        for (int i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");

    }
}

void sort_destroy(Sort *self) {
    free(self->data);
}

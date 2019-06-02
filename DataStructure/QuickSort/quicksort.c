//
//  quicksort.c
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "quicksort.h"
#include <stdlib.h>

#define MAX(a, b)       (((a) > (b) ) ? (a) : (b))
#define MIN(a, b)       (((a) < (b) ) ? (a) : (b))
#define MID(a,b,c)      (MAX(a,b)>c?MAX(MIN(a,b),c):MIN(MAX(a,b),c))

Quicksort new_quicksort(int n) {
    Quicksort newquicksort;
    
    newquicksort.data = malloc(sizeof *(newquicksort.data) * n);
    
    newquicksort.size = n;
    return newquicksort;
}

void sort_quicksort(int *data, int first, int last, int step) {
    
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
        
        printf("current partitioning step: %d\n", step);
        for (int s = first; s <= last; s++) {
            if (s == i && last - first > 1) printf("|");
            printf("%d", data[s]);
            if (s == i &&  last - first > 1) printf("|");
            if (s != last) {
                printf("->");
            }
        }
        printf("\n");
        step++;
        
        sort_quicksort(data, first, j, step);
        sort_quicksort(data, i+1, last, step);
    }
}

void sort(Quicksort *self, int step) {
    sort_quicksort(self->data, 0, self->size - 1, 0);
}

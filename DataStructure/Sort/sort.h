//
//  sort.h
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

typedef struct sort {
    int size;
    int *data;
} Sort;

Sort new_sort(int n);

void sort_quicksort(Sort *self);
void sort_radixsort(Sort *self);

void sort_destroy(Sort *self);

#endif /* quicksort_h */

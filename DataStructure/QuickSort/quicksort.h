//
//  quicksort.h
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>

typedef struct quicksort {
    int size;
    int *data;
} Quicksort;

Quicksort new_quicksort(int n);

void sort(Quicksort *self, int step);

#endif /* quicksort_h */

//
//  heap.h
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>

typedef struct heap {
    int size;
    int *heap;
} Heap;

Heap new_heap(int n);

void heap_insert(Heap *self, int n, int data);
void max_heap_insert(Heap *self, int n, int data);
void min_heap_insert(Heap *self, int n, int data);

void max_heap_sort(Heap *self);
void min_heap_sort(Heap *self);

int min_heap_delete(Heap *self);
int max_heap_delete(Heap *self);

void print_heap(Heap *self);

void heap_destroy(Heap *self);

#endif /* heap_h */

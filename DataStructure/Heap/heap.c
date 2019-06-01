//
//  heap.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "heap.h"
#include <stdlib.h>

Heap new_heap(int n) {
    Heap newheap;
    
    newheap.heap = malloc(sizeof *(newheap.heap) * n);

    newheap.size = n;
    return newheap;
}

void heap_insert(Heap *self, int n, int data) {
    if (n == self->size) {
        printf("The heap is full.\n");
        exit(1);
    }
    
    self->heap[n] = data;
}

void max_heap_sort(Heap *self) {
    
    if (self->size == 0) {
        printf("The heap is empty.\n");
        exit(1);
    }
    
    int n = self->size - 1;
    int parent = (n-1) / 2;
    
    while (n != 0) {
        if (n == (parent+1) * 2 && self->heap[n] < self->heap[n-1]) {
            n--;
        }
        
        if (self->heap[n] > self->heap[parent]) {
            int temp = self->heap[n];
            self->heap[n] = self->heap[parent];
            self->heap[parent] = temp;
            
            int data = self->heap[n];
            int child = n * 2 + 1;
            while (child < self->size) {
                if (child < self->size - 1 && self->heap[child + 1] > self->heap[child]) {
                    child++;
                }
                if (self->heap[child] > data) {
                    self->heap[n] = self->heap[child];
                    n = child;
                    child = n * 2 + 1;
                } else {
                    break;
                }
            }
            self->heap[n] = data;
            
        }
        
        n = (parent+1) * 2 - 2;
        parent = (n-1) / 2;
    }
}

void min_heap_insert(Heap *self, int n, int data) {
    
    if (self->size == n) {
        printf("The heap is full.\n");
        exit(1);
    }
    
    int parent = (n-1) / 2;
    while ((n != 0) && (data < self->heap[parent])) {
        self->heap[n] = self->heap[parent];
        n = parent;
        parent = (n-1) / 2;
    }
    self->heap[n] = data;
}

void max_heap_insert(Heap *self, int n, int data) {

    if (self->size == n) {
        printf("The heap is full.\n");
        exit(1);
    }

    int parent = (n-1) / 2;
    while ((n != 0) && (data > self->heap[parent])) {
        self->heap[n] = self->heap[parent];
        n = parent;
        parent = (n-1) / 2;
    }
    self->heap[n] = data;
}

void min_heap_sort(Heap *self) {
    
    if (self->size == 0) {
        printf("The heap is empty.\n");
        exit(1);
    }
    
    int n = self->size - 1;
    int parent = (n-1) / 2;
    
    while (n != 0) {
        if (n == (parent+1) * 2 && self->heap[n] > self->heap[n-1]) {
            n--;
        }
        
        if (self->heap[n] < self->heap[parent]) {
            int temp = self->heap[n];
            self->heap[n] = self->heap[parent];
            self->heap[parent] = temp;
            
            int data = self->heap[n];
            int child = n * 2 + 1;
            while (child < self->size) {
                if (child < self->size - 1 && self->heap[child + 1] < self->heap[child]) {
                    child++;
                }
                if (self->heap[child] < data) {
                    self->heap[n] = self->heap[child];
                    n = child;
                    child = n * 2 + 1;
                } else {
                    break;
                }
            }
            self->heap[n] = data;
            
        }
        
        n = (parent+1) * 2 - 2;
        parent = (n-1) / 2;
    }
}

int min_heap_delete(Heap *self) {
    
    if (self->size == 0) {
        printf("The heap is empty.\n");
        exit(1);
    }
        
    int n = 0;
    int result = self->heap[0];
    int data = self->heap[--self->size];
    int child = n * 2 + 1;
    
    while (child < self->size) {
        if (child < self->size - 1 && self->heap[child + 1] < self->heap[child]) {
            child++;
        }
        if (self->heap[child] < data) {
            self->heap[n] = self->heap[child];
            n = child;
            child = n * 2 + 1;
        } else {
            break;
        }
    }
    self->heap[n] = data;
    
    return result;
}

int max_heap_delete(Heap *self) {

    if (self->size == 0) {
        printf("The heap is empty.\n");
        exit(1);
    }
    
    int n = 0;
    int result = self->heap[0];
    int data = self->heap[--self->size];
    int child = n * 2 + 1;
    
    while (child < self->size) {
        if (child < self->size - 1 && self->heap[child + 1] > self->heap[child]) {
            child++;
        }
        if (self->heap[child] > data) {
            self->heap[n] = self->heap[child];
            n = child;
            child = n * 2 + 1;
        } else {
            break;
        }
    }
    self->heap[n] = data;
    
    return result;
}

void print_heap(Heap *self) {
    for (int i = 0; i < self->size; i++) {
        printf("[%d] = %d\n", i, self->heap[i]);
    }
    printf("\n");
}

void heap_destroy(Heap *self) {
    free(self->heap);
}

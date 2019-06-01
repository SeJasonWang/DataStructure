//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include "heap.h"

int main() {
    
    Heap heap = new_heap(9);

    heap_insert(&heap, 0, 21);
    heap_insert(&heap, 1, 13);
    heap_insert(&heap, 2, 3);
    heap_insert(&heap, 3, 1);
    heap_insert(&heap, 4, 9);
    heap_insert(&heap, 5, 11);
    heap_insert(&heap, 6, 8);
    heap_insert(&heap, 7, 7);
    heap_insert(&heap, 8, 5);
    
    print_heap(&heap);
    
    max_heap_sort(&heap);
    
    print_heap(&heap);

    printf("%d->", max_heap_delete(&heap));
    printf("%d->", max_heap_delete(&heap));
    printf("%d\n", max_heap_delete(&heap));

    print_heap(&heap);

    return 0;
}

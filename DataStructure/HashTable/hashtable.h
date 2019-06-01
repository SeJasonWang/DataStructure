//
//  hashtable.h
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>
#include "list.h"

typedef struct hashTable {
    int size;
    List *table;
} HashTable;

HashTable create_hashtable(int n);

void hash_insert(HashTable *self, int data);
void hash_remove(HashTable *self, int data);

void hash_print(HashTable *self);

void hash_destroy(HashTable *self);

#endif /* hashtable_h */

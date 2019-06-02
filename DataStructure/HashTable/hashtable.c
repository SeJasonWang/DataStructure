//
//  hashtable.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "hashtable.h"
#include <stdlib.h>

HashTable new_hashtable(int n) {
    HashTable newtable;
    
    newtable.table = malloc(sizeof *(newtable.table) * n);
    for (int i = 0; i < n; i++) {
        newtable.table[i].head = NULL;
    }
    newtable.size = n;
    return newtable;
}

void hash_insert(HashTable *self, int data) {
    int i = data % self->size;
    insert_at_front(&(self->table[i]), data);
}

void hash_remove(HashTable *self, int data) {
    int i = data % self->size;
    delete_list(&self->table[i], data);
}

void hash_print(HashTable *self) {
    for (int i = 0; i < self->size; i++) {
        printf("%d: ", i);
        print_list(&(self->table[i]));
    }
}

void hash_destroy(HashTable *self) {
    for (int i = 0; i < self->size; i++) {
        destroy_list(&self->table[i]);
    }
    free(self->table);
}

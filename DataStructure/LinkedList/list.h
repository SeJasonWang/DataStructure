//
//  list.h
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} *ListNodePtr;

typedef struct list {
    ListNodePtr head;
} List;

List new_list(void);

void insert_at_front(List *self, int data);
void inset_in_order(List *self, int data);

void reverse_list(List *self);
void merge_list(List *self, List *addition);
List unzip(List *self); // unzip even nodes from self to a new list

void print_list(List *self);

void delete_list(List *self, int data);
void destroy_list(List *self);

#endif /* list_h */

//
//  skiplist.h
//  DataStructure
//
//  Created by Jason on 3/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef skiplist_h
#define skiplist_h

#include <stdio.h>

#define SKIPLIST_MAX_LEVEL 4

typedef struct skipnode {
    int data;
    struct skipnode **next;
} *SkipNodePtr;

typedef struct skiplist {
    int level;
    SkipNodePtr header;
} Skiplist;


Skiplist new_skiplist(void);
SkipNodePtr skiplist_find(Skiplist *self, int data);

void skiplist_insert(Skiplist *self, int data, int level);
void skiplist_delete(Skiplist *self, int data);
void skiplist_print(Skiplist *self);

void skiplist_free(Skiplist *self);

int rand_level(void);

#endif /* skiplist_h */

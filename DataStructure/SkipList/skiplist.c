//
//  skiplist.c
//  DataStructure
//
//  Created by Jason on 3/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "skiplist.h"
#include <stdlib.h>

#define MIN(a, b)    ((a) < (b) ? (a) : (b))

Skiplist new_skiplist(void) {
    int i;
    
    Skiplist list;
    
    list.header = malloc(sizeof *(list.header));
    list.header->data = 0;
    list.header->next = malloc(SKIPLIST_MAX_LEVEL * sizeof *(list.header->next));
    for (i = 0; i < SKIPLIST_MAX_LEVEL; i++) {
        list.header->next[i] = NULL;
    }
    
    list.level = SKIPLIST_MAX_LEVEL;
    
    return list;
}

void skiplist_insert(Skiplist *self, int data, int level) {
    SkipNodePtr current = self->header;
    SkipNodePtr node = malloc(sizeof *(node));
    node->data = data;
    
    level = MIN(self->level, level);
    
    node->next = malloc(sizeof *(node->next) * level);
    
    for (int i = level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->data < data) {
            current = current->next[i];
        }
        node->next[i] = current->next[i];
        current->next[i] = node;
    }
}

void skiplist_print(Skiplist *self) {
    int i;
    for (i = self->level - 1; i >= 0; i--) {
        SkipNodePtr current = self->header->next[i];
        printf("level %d: ", i);
        
        while (current != NULL) {
            printf("%d", current->data);
            current = current->next[i];
            if (current != NULL) {
                printf("->");
            }
        }
        printf("\n");
    }
    printf("\n");
}

SkipNodePtr skiplist_find(Skiplist *self, int data) {
    SkipNodePtr current = self->header;
    int i;
    for (i = self->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->data < data) {
            current = current->next[i];
        }
        
        if (current->next[i] != NULL && current->next[i]->data == data) {
            return current->next[i];
        }
    }
    return NULL;
}

void skiplist_delete(Skiplist *self, int data) {
    SkipNodePtr current = self->header;
    int i;
    SkipNodePtr tofree = NULL;
    for (i = self->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->data < data) {
            current = current->next[i];
        }
        
        if (current->next[i] != NULL && current->next[i]->data == data) {
            if (tofree == NULL) {
                tofree = current->next[i];
            }
            current->next[i] = current->next[i]->next[i];
        }
    }
    if (tofree) {
        free(tofree);
    }
}

void skiplist_free(Skiplist *self) {
    SkipNodePtr current = self->header;
    while (current != NULL) {
        SkipNodePtr to_free = current;
        current = current->next[0];
        free(to_free);
    }
    self->header = NULL;
}

int rand_level(void) {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

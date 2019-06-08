//
//  queue.c
//  DataStructure
//
//  Created by Jason on 6/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

Queue new_queue(void) {
    Queue temp;
    temp.head = NULL;
    temp.tail = NULL;
    return temp;
}

void enqueue(Queue *self, int i) {
    QueueNodePtr new_node = malloc(sizeof *new_node);
    new_node->i = i;
    new_node->next = NULL;
    
    if (self->head == NULL) {
        new_node->next = self->head;
        self->head = new_node;
        self->tail = new_node;
    } else {
        self->tail->next = new_node;
        self->tail = new_node;
    }
}

int dequeue(Queue *self) {
    if (self->head) {
        QueueNodePtr current = self->head;
        int i = current->i;
        
        self->head = current->next;
        free(current);
        
        if (self->head == NULL) {
            self->tail = NULL;
        }
        
        return i;
    } else {
        return -1;
    }
}

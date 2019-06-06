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
    return temp;
}

void enqueue(Queue *self, int i) {
    QueueNodePtr new_node = malloc(sizeof *new_node);
    new_node->i = i;
    
    if (self->head == NULL) {
        new_node->next = self->head;
        self->head = new_node;
    } else {
        QueueNodePtr current = self->head;
        while(current->next != NULL) {
            current = current->next;
        }
        new_node->next = NULL;
        current->next = new_node;
    }
}

int dequeue(Queue *self) {
    if (self->head) {
        QueueNodePtr current = self->head;
        int i = current->i;
        
        self->head = current->next;
        free(current);
        
        return i;
    } else {
        return -1;
    }
}

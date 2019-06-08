//
//  queue.h
//  DataStructure
//
//  Created by Jason on 6/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef struct queueNode {
    int i;
    struct queueNode *next;
} *QueueNodePtr;

typedef struct queue {
    QueueNodePtr head;
    QueueNodePtr tail;
} Queue;

Queue new_queue(void);

void enqueue(Queue *self, int i);
int dequeue(Queue *self);

#endif /* queue_h */

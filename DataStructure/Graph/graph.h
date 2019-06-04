//
//  graph.h
//  DataStructure
//
//  Created by Jason on 4/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

typedef struct edgeNode {
    int to_vertex;
    struct edgeNode *next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList *edges;
} Graph;

Graph new_graph(int n);

void insert_at_front_edgelist(EdgeList *list, int to_vertex);
void print_graph(Graph *self);

void dfs(Graph *self, int start);

#endif /* graph_h */

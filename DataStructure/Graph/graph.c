//
//  graph.c
//  DataStructure
//
//  Created by Jason on 4/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "graph.h"
#include <stdlib.h>
#include "queue.h"

Graph new_graph(int n) {
    
    Graph graph;
    graph.edges = malloc(sizeof *(graph.edges) * n);
    graph.V = n;
    
    for (int i = 0; i < n; i++) {
        graph.edges[i].head = NULL;
    }
    return graph;
}

void insert_at_front_edgelist(EdgeList *list, int to_vertex) {
    EdgeNodePtr new_node = malloc(sizeof *new_node);
    new_node->to_vertex = to_vertex;
    new_node->next = list->head;
    list->head = new_node;
}

void print_graph(Graph *self) {
    for (int i = 0; i < self->V; i++) {
        EdgeNodePtr current = self->edges[i].head;
        printf("V(%d): ", i);
        while (current != NULL) {
            printf("(%d)", current->to_vertex);
            current = current->next;
            
            if (current != NULL)
                printf(", ");
        }
        printf("\n");
    }
}

void dfs_vertex(Graph *self, int start, int *visited) {
    if (visited[start] == 0) {
        visited[start] = 1;
        
        EdgeNodePtr current = self->edges[start].head;
        printf("current v: %d\n", start);
        
        while (current != NULL) {
            dfs_vertex(self, current->to_vertex, visited);
            current = current->next;
        }
    }
}

void dfs(Graph *self, int start) {
    int *visited = malloc(sizeof *(visited) * self->V);
    for (int i = 0; i < self->V; i++) {
        visited[i] = 0;
    }
    
    dfs_vertex(self, start, visited);
    free(visited);
}

void bfs_vertex(Graph *self, int start, Queue *queue, int *visited) {
    if (start != -1) {
        
        EdgeNodePtr current = self->edges[start].head;
        printf("current v: %d\n", start);

        while (current != NULL) {
            if (visited[current->to_vertex] == 0) {
                visited[current->to_vertex] = 1;
                enqueue(queue, current->to_vertex);
            }
            current = current->next;
        }
        bfs_vertex(self, dequeue(queue), queue, visited);
    }
}

void bfs(Graph *self, int start) {
    int *visited = malloc(sizeof *(visited) * self->V);
    for (int i = 0; i < self->V; i++) {
        visited[i] = (i == start) ? 1 : 0;
    }
    
    Queue q = new_queue();
    bfs_vertex(self, start, &q, visited);
}

int inDegree(Graph *self, int v) {
    int inDegree = 0;
    for (int i = 0; i < self->V; i++) {
        EdgeNodePtr current = self->edges[i].head;
        while (current != NULL) {
            if (current->to_vertex == v) {
                inDegree++;
            }
            current = current->next;
        }
    }
    return inDegree;
}

int outDegree(Graph *self, int v) {
    int outDegree = 0;
    EdgeNodePtr current = self->edges[v].head;
    while (current != NULL) {
        outDegree++;
        current = current->next;
    }
    return outDegree;
}

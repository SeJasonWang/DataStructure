//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    
    Graph graph = new_graph(9);
    
    insert_at_front_edgelist(&graph.edges[0], 4);
    insert_at_front_edgelist(&graph.edges[0], 3);
    insert_at_front_edgelist(&graph.edges[0], 1);
    insert_at_front_edgelist(&graph.edges[1], 5);
    insert_at_front_edgelist(&graph.edges[1], 4);
    insert_at_front_edgelist(&graph.edges[1], 2);
    insert_at_front_edgelist(&graph.edges[2], 5);
    insert_at_front_edgelist(&graph.edges[3], 7);
    insert_at_front_edgelist(&graph.edges[3], 6);
    insert_at_front_edgelist(&graph.edges[3], 4);
    insert_at_front_edgelist(&graph.edges[4], 8);
    insert_at_front_edgelist(&graph.edges[4], 7);
    insert_at_front_edgelist(&graph.edges[4], 5);
    insert_at_front_edgelist(&graph.edges[5], 8);
    insert_at_front_edgelist(&graph.edges[6], 7);
    insert_at_front_edgelist(&graph.edges[7], 8);
    
    print_graph(&graph);
    
    bfs(&graph, 0);
    
    return 0;
    
}

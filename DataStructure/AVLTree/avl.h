//
//  avl.h
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef avl_h
#define avl_h

#include <stdio.h>

typedef struct avlNode {
    int data;
    int height;
    struct avlNode *left;
    struct avlNode *right;
} *AVLNodePtr;

typedef struct avl {
    AVLNodePtr root;
} AVL;

AVL new_avl(void);

void insert_avl(AVL *self, int n);
void delete_avl(AVL *self, int n);

AVLNodePtr find_avl(AVL *self, int n);
AVLNodePtr min_node_avl(AVLNodePtr self);
AVLNodePtr max_node_avl(AVLNodePtr self);

int height_avl(AVL *self);
int number_avl(AVL *self);

void print_pre_order_avl(AVL *self);
void print_in_order_avl(AVL *self);
void print_post_order_avl(AVL *self);

void destroy_avl(AVL *self);

#endif /* avl_h */

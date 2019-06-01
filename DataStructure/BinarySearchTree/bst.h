//
//  bst.h
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdio.h>

typedef struct bstNode {
    int data;
    struct bstNode *left;
    struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
    BSTNodePtr root;
} BST;

BST new_bst(void);

void insert_bst(BST *self, int data);
void delete_bst(BST *self, int data);

BSTNodePtr find_bst(BST *self, int data);
BSTNodePtr min_node_bst(BSTNodePtr self);
BSTNodePtr max_node_bst(BSTNodePtr self);

int height_bst(BST *self);
int number_bst(BST *self);

void print_pre_order_bst(BST *self);
void print_in_order_bst(BST *self);
void print_post_order_bst(BST *self);

void destroy_bst(BST *self);

#endif /* bst_h */

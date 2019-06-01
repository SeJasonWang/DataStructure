//
//  bst.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "bst.h"
#include <stdlib.h>

BST new_bst() {
    BST temp;
    temp.root = NULL;
    return temp;
}

BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
    if (self == NULL) { /* found where to put it*/
        self = malloc(sizeof *self);
        self->data = n;
        self->left = self->right = NULL;
    } else if (n < self->data) {
        self->left = insert_bst_node(self->left, n);
    } else if (n > self->data) {
        self->right = insert_bst_node(self->right, n);
    }
    return self;
}

void insert_bst(BST *self, int n) {
    self->root = insert_bst_node(self->root, n);
}

BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
    if (self != NULL) {
        if (n == self->data) { // found item
            if (self->left != NULL && self->right != NULL) {
                // two child case
                BSTNodePtr successor = min_node(self->right);
                self->data = successor->data;
                self->right = delete_bst_node(self->right, self->data);
            } else { // one or zero child case
                BSTNodePtr to_free = self;
                if (self->left) {
                    self = self->left;
                } else {
                    self = self->right;
                }
                free(to_free);
            }
        } else if (n < self->data) {
            self->left = delete_bst_node(self->left, n);
        } else {
            self->right = delete_bst_node(self->right, n);
        }
    }
    return self;
}

void delete_bst(BST *self, int n) {
    self->root = delete_bst_node(self->root, n);
}

BSTNodePtr find_bst_node(BSTNodePtr self, int n){
    if (self == NULL || (n == self->data)) {
        return self;
    } else if (n < self->data) {
        return find_bst_node(self->left, n);
    } else {
        return find_bst_node(self->right, n);
    }
}

BSTNodePtr find_bst(BST *self, int n) {
    return find_bst_node(self->root, n);
}

BSTNodePtr min_node(BSTNodePtr self) {
    BSTNodePtr current = self;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

int height_bst_node(BSTNodePtr self) {
    
    if (self == NULL) {
        return 0;
    }

    int left_height = height_bst_node(self->left);
    int right_eight = height_bst_node(self->right);
    
    return 1 + (left_height > right_eight ? left_height : right_eight);
}

int height_bst(BST *self) {
    return height_bst_node(self->root);
}

void print_pre_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        printf(" %d ", self ->data);
        print_pre_order_bst_node(self ->left);
        print_pre_order_bst_node(self ->right);
        printf(")");
    } else {
        printf("_");
    }
}

void print_in_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_in_order_bst_node(self ->left);
        printf(" %d ", self ->data);
        print_in_order_bst_node(self ->right);
        printf(")");
    } else {
        printf("_");
    }
}

void print_post_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_post_order_bst_node(self ->left);
        print_post_order_bst_node(self ->right);
        printf(" %d ", self ->data);
        printf(")");
    } else {
        printf("_");
    }
}

void print_pre_order_bst(BST *self) {
    print_pre_order_bst_node(self->root);
}

void print_in_order_bst(BST *self) {
    print_in_order_bst_node(self->root);
}

void print_post_order_bst(BST *self) {
    print_post_order_bst_node(self->root);
}

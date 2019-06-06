//
//  avl.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include "avl.h"
#include <stdlib.h>

#define HEIGHT(p)    ((p == NULL) ? 0 : (p->height))
#define MAX(a, b)    ((a) > (b) ? (a) : (b))

AVLNodePtr left_left_rotation(AVLNodePtr self) {
    AVLNodePtr left = self->left;
    self->left = left->right;
    left->right = self;
    
    self->height = MAX(HEIGHT(self->left), HEIGHT(self->right)) + 1;
    left->height = MAX(HEIGHT(left->left), self->height) + 1;
    
    return left;
}

AVLNodePtr right_right_rotation(AVLNodePtr self) {
    AVLNodePtr right = self->right;
    self->right = right->left;
    right->left = self;
    
    self->height = MAX(HEIGHT(self->left), HEIGHT(self->right)) + 1;
    right->height = MAX(HEIGHT(right->right), self->height) + 1;
    
    return right;
}

AVLNodePtr left_right_rotation(AVLNodePtr self) {
    self->left = right_right_rotation(self->left);
    
    return left_left_rotation(self);
}

AVLNodePtr right_left_rotation(AVLNodePtr self) {
    self->right = left_left_rotation(self->right);
    
    return right_right_rotation(self);
}

AVL new_avl() {
    AVL temp;
    temp.root = NULL;
    return temp;
}

AVLNodePtr insert_avl_node(AVLNodePtr self, int n) {
    if (self == NULL) {
        self = malloc(sizeof(*self));
        self->data = n;
        self->height = 0;
        self->right = self->left = NULL;
    } else if (self->data > n) {
        self->left = insert_avl_node(self->left, n);
        
        // balance
        if (HEIGHT(self->left) - HEIGHT(self->right) == 2) {
            if (self->left->data > n) {
                self = left_left_rotation(self);
            } else {
                self = left_right_rotation(self);
            }
        }
        
    } else if (self->data < n) {
        self->right = insert_avl_node(self->right, n);
        
        // balance
        if (HEIGHT(self->right) - HEIGHT(self->left) == 2) {
            if (self->right->data < n)
                self = right_right_rotation(self);
            else
                self = right_left_rotation(self);
        }
    }
    
    self->height = MAX(HEIGHT(self->left), HEIGHT(self->right)) + 1;
    
    return self;
}

void insert_avl(AVL *self, int n) {
    self->root = insert_avl_node(self->root, n);
}

AVLNodePtr find_avl_node(AVLNodePtr self, int n) {
    if (self == NULL || (self->data == n)) {
        return self;
    } else if (n < self->data) {
        return find_avl_node(self->left, n);
    } else {
        return find_avl_node(self->right, n);
    }
}

AVLNodePtr find_avl(AVL *self, int n) {
    return find_avl_node(self->root, n);
}

AVLNodePtr min_node_avl(AVLNodePtr self) {
    AVLNodePtr current = self;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

AVLNodePtr max_node_avl(AVLNodePtr self) {
    AVLNodePtr current = self;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

AVLNodePtr delete_avl_node(AVLNodePtr self, int n) {
    if (self != NULL) {
        if (self->data == n) { // found item
            if (self->left != NULL && self->right != NULL) { // two child case
                if (HEIGHT(self->left) > HEIGHT(self->right)) {
                    AVLNodePtr successor = max_node_avl(self->left);
                    self->data = successor->data;
                    self->left = delete_avl_node(self->left, self->data);
                } else {
                    AVLNodePtr successor = min_node_avl(self->right);
                    self->data = successor->data;
                    self->right = delete_avl_node(self->right, self->data);
                }
            } else { // one or zero child case
                AVLNodePtr to_free = self;
                if (self->left) {
                    self = self->left;
                } else {
                    self = self->right;
                }
                free(to_free);
            }
        } else if (self->data > n) {
            self->left = delete_avl_node(self->left, n);

            // balance
            if (HEIGHT(self->right) - HEIGHT(self->left) == 2) {
                AVLNodePtr right = self->right;
                if (HEIGHT(right->left) > HEIGHT(right->right)) {
                    self = right_left_rotation(self);
                } else {
                    self = right_right_rotation(self);
                }
            }
        } else {
            self->right = delete_avl_node(self->right, n);

            // balance
            if (HEIGHT(self->left) - HEIGHT(self->right) == 2) {
                AVLNodePtr left = self->left;
                if (HEIGHT(left->right) > HEIGHT(left->left)) {
                    self = left_right_rotation(self);
                } else {
                    self = left_left_rotation(self);
                }
            }
        }
    }
    
    if (self != NULL) {
        self->height = MAX(HEIGHT(self->left), HEIGHT(self->right)) + 1;
    }

    return self;
}

void delete_avl(AVL *self, int n) {
    self->root = delete_avl_node(self->root, n);
}

int height_avl_node(AVLNodePtr self) {
    if (self == NULL) {
        return 0;
    }
    
    int left_height = height_avl_node(self->left);
    int right_eight = height_avl_node(self->right);
    
    return 1 + (left_height > right_eight ? left_height : right_eight);
}

int height_avl(AVL *self) {
    return height_avl_node(self->root);
}

int number_avl_node(AVLNodePtr self) {
    if (self == NULL) {
        return 0;
    }
    
    return 1 + number_avl_node(self->left) + number_avl_node(self->right);
}

int number_avl(AVL *self) {
    return number_avl_node(self->root);
}

void print_pre_order_avl_node(AVLNodePtr self) {
    if (self != NULL) {
        printf("(");
        printf(" %d ", self ->data);
        print_pre_order_avl_node(self ->left);
        print_pre_order_avl_node(self ->right);
        printf(")");
    } else {
        printf("_");
    }
}

void print_in_order_avl_node(AVLNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_in_order_avl_node(self ->left);
        printf(" %d ", self ->data);
        print_in_order_avl_node(self ->right);
        printf(")");
    } else {
        printf("_");
    }
}

void print_post_order_avl_node(AVLNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_post_order_avl_node(self ->left);
        print_post_order_avl_node(self ->right);
        printf(" %d ", self ->data);
        printf(")");
    } else {
        printf("_");
    }
}

void print_pre_order_avl(AVL *self) {
    print_pre_order_avl_node(self->root);
    printf("\n");
}

void print_in_order_avl(AVL *self) {
    print_in_order_avl_node(self->root);
    printf("\n");

}

void print_post_order_avl(AVL *self) {
    print_post_order_avl_node(self->root);
    printf("\n");
}

void free_avl_node(AVLNodePtr self) {
    if (self != NULL) {
        free_avl_node(self->left);
        free_avl_node(self->right);
        free(self);
    }
}

void destroy_avl(AVL *self) {
    free_avl_node(self->root);
    self->root = NULL;
}

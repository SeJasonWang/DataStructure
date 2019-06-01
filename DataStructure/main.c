//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include "bst.h"

void print_height(BST *self) {
    printf("height: %d\n", height_bst(self));
}

void insert(BST *self) {
    printf("Enter some data to add: ");
    int data;
    scanf("%d", &data);
    insert_bst(self, data);
}

void delete(BST *self) {
    printf("Enter some data to delete: ");
    int data;
    scanf("%d", &data);
    delete_bst(self, data);
}

void print(BST *self) {
    print_pre_order_bst(self);
    printf("\n");
    print_in_order_bst(self);
    printf("\n");
    print_post_order_bst(self);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    printf("Week4!\n");
    
    BST tree = new_bst();
    int quit = 0;
    int option;
    
    while (quit == 0) {
        scanf("%d", &option);
        switch (option) {
            case 0:
                quit = 1;
                break;
            case 1:
                insert(&tree);
                break;
            case 2:
                delete(&tree);
                break;
            case 3:
                print(&tree);
                break;
            case 4:
                print_height(&tree);
                break;
        }
    }
    
    return 0;
}

//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include "avl.h"

void print_height(AVL *self) {
    printf("height: %d\n", height_avl(self));
}

void insert(AVL *self) {
    printf("Enter some data to add: ");
    int data;
    scanf("%d", &data);
    insert_avl(self, data);
}

void delete(AVL *self) {
    printf("Enter some data to delete: ");
    int data;
    scanf("%d", &data);
    delete_avl(self, data);
}

void print(AVL *self) {
    print_pre_order_avl(self);
    printf("\n");
    print_in_order_avl(self);
    printf("\n");
    print_post_order_avl(self);
    printf("\n");
}

int main(int argc, const char * argv[]) {
        
    AVL tree = new_avl();
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

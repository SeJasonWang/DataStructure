//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include "hashtable.h"

int main(){
    
    int command = 1;
    HashTable table = create_hashtable(11);
    int buffer;
    
    while (command) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                printf("Enter some data to add: ");
                scanf("%d", &buffer);
                hash_insert(&table, buffer);
                break;
            case 2:
                printf("Enter some data to remove: ");
                scanf("%d", &buffer);
                hash_remove(&table, buffer);
                break;
            case 3:
                hash_print(&table);
                break;
        }
        printf("\n");
    }
    hash_destroy(&table);
}


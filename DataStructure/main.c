//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

int main() {
    
    SkipNodePtr found;
    int arr[] = {5,7,1,12,8,14,9,4,10,2};
    int level[] = {3,2,1,1,1,2,4,3,1,4};
    int n = 10;
    Skiplist list = new_skiplist();
    
    printf("Insert:--------------------\n");
    for (int i = 0; i < n; i++) {
        skiplist_insert(&list, arr[i], level[i]);
    }
    skiplist_print(&list);
    
    found = skiplist_find(&list, 7);
    if (found) {
        printf("found %d\n", found->data);
    } else {
        printf("not found %d\n", 7);
    }
    
    found = skiplist_find(&list, 3);
    if (found) {
        printf("found %d\n", found->data);
    } else {
        printf("not found %d\n", 3);
    }
    
    skiplist_delete(&list, 3);
    skiplist_delete(&list, 9);
    skiplist_print(&list);
    
    skiplist_free(&list);
    
    return 0;

}

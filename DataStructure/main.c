//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    
    BST bst = new_bst();
    insert_bst(&bst, 6);
    insert_bst(&bst, 2);
    insert_bst(&bst, 8);
    insert_bst(&bst, 1);
    insert_bst(&bst, 3);
    insert_bst(&bst, 11);
    insert_bst(&bst, 5);
    insert_bst(&bst, 9);

    printf("%d\n", number_bst_oneChild(&bst));
    
    return 0;
    
}

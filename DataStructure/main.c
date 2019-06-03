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
    
    insert_bst(&bst, 7);
    insert_bst(&bst, 2);
    insert_bst(&bst, 8);
    insert_bst(&bst, 1);
    insert_bst(&bst, 3);
    insert_bst(&bst, 14);
    insert_bst(&bst, 5);
    insert_bst(&bst, 12);

    print_in_order_bst(&bst);
    
    printf("\nfind %d\n", nearest_match(&bst, 0));
    
    return 0;

}

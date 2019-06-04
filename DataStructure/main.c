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
    
    int a[7] = {1,2,3,4,5,6,7};
    
    BST bst = arrayToBST(a, 0, 6);
    
    print_in_order_bst(&bst);
    
    return 0;

}

//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include "quicksort.h"

int main() {
    
    Quicksort q = new_quicksort(9);
    int a[9] = {21, 13, 3, 1, 9, 11, 8, 7, 5};
    q.data = a;
    
    sort(&q, 0);
        
    return 0;
}

//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main() {
    
    Sort s = new_sort(14);
    int data[14] = {32,12,34,87,20,23,6,30,24,26,43,46,70,64};

    free(s.data);
    s.data = data;
    
    sort_radixsort(&s);
        
    return 0;
}

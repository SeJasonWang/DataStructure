//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "dynamicprogramming.h"

int main() {
    
    int weight[10] = {0, 1, 1, 3, 2, 4, 3, 6, 5, 7};
    int value[10] = {100, 150, 50, 25, 2, 15, 1000, 25, 55, 225};
    int capacity = 10;
    int n = 10;
    
    printf("total value: %d\n", simple_recursion(weight, value, capacity, n));

    return 0;
}

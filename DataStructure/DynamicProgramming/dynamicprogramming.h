//
//  dynamicprogramming.h
//  DataStructure
//
//  Created by Jason on 2/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#ifndef dynamicprogramming_h
#define dynamicprogramming_h

#include <stdio.h>

int recursion_knapsackValue(int weight[], int value[], int capacity, int n);
int dynamic_knapsackValue(int weight[], int value[], int capacity, int n);

int dynamic_subsequence(int value[], int n);

#endif /* dynamicprogramming_h */

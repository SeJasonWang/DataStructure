//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "bigo.h"

int main(int argc, const char * argv[]) {
    
    int quit = 0;
    while (!quit) {
        int option;
        scanf("%d", &option);
        
        if (option == 0) {
            quit = 1;
        } else {
            long n;
            printf("Enter a value for n\n");
            scanf("%ld", &n);
            clock_t start = clock();
            
            switch (option) {
                case 1:
                    f1(n);
                    break;
                case 2:
                    f2(n);
                    break;
                case 3:
                    f3(n);
                    break;
                case 4:
                    f4(n);
                    break;
                case 5:
                    f5(n);
                    break;
                case 6:
                    f6(n);
                    break;
                case 7:
                    f7(n);
                    break;
                case 8:
                    f8(n);
                    break;
            }
            
            clock_t diff = clock() - start;
            long msec = diff * 1000 / CLOCKS_PER_SEC;
            printf("Operation took %ld milliseconds\n\n", msec);
        }
    }
    
    return 0;
}

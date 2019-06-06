//
//  main.c
//  DataStructure
//
//  Created by Jason on 1/6/19.
//  Copyright © 2019 UTAS. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    
    List list = new_list();
    
    for (int i = 8; i >= 1; i--) {
        insert_at_front(&list, i);
    }
    printf("original list: ");
    print_list(&list);

    List unzipedList = unzip(&list);
    printf("original list: ");
    print_list(&list);
    printf("unzipped list: ");
    print_list(&unzipedList);
    
    List zippedList = zip(&list, &unzipedList);
    printf("zipped list: ");
    print_list(&zippedList);
    
    destroy_list(&zippedList);
    list.head = NULL;
    unzipedList.head = NULL;

    return 0;
    
}

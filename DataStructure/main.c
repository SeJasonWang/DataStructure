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
    
    List unzipedList = unzip(&list);
    
    printf("original list: ");
    print_list(&list);
    printf("unzipped list: ");
    print_list(&unzipedList);
    
    destroy_list(&list);
    destroy_list(&unzipedList);
    
    return 0;

}

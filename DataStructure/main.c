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
    
    insert_at_front(&list, 6);
    insert_at_front(&list, 5);
    insert_at_front(&list, 4);
    insert_at_front(&list, 3);
    insert_at_front(&list, 2);
    insert_at_front(&list, 1);

    printf("%d\n", median(&list));
    
    return 0;

}

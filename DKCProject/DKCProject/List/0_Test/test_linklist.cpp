//
//  test_linklist.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/10.
//  Copyright © 2021 dk. All rights reserved.
//

#include "test_linklist.hpp"

void test_linklist() {
//    LinkList L;
//    List_HeadInsert(L);
//    List_TailInsert(L);
    
    int arr[20] = {1,2,4,6,7,8,9};
    LinkList L = ListInit(arr, 7);
    PrintLinkList(L);
    
//    LNode *node = GetElem(L, 3);
//    printf("get node %d \n", node->data);
    
    InsertNode(L, 1, 99);
    PrintLinkList(L);
    InsertNode(L, 0, 99);
    PrintLinkList(L);
    InsertNode(L, 8, 99);
    PrintLinkList(L);
    InsertNode(L, 10, 99);
    PrintLinkList(L);
    
    printf("len = %d \n", LinkListLength(L));
}

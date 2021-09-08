//
//  test_linklist.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/10.
//  Copyright © 2021 dk. All rights reserved.
//

#include "LinkList.hpp"
#include "LinkList_Q.hpp"

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

void test_dLinklist() {
    int arr[20] = {1,2,4,6,7,8,9};
    
    DLinklist tail = NULL;
    DLinklist L = DLinklistInit(arr, 7, tail);
    PrintDLinklist(L);
    PrintDLinklist(tail, false);
    
//    printf("tail = %d \n", tail->prior->prior->data);
}

void test_linklist_q() {
    
    int arr[20] = {1,2,4,6,7,7,8,9};
    LinkList L = ListInit(arr, 8);
    PrintLinkList(L);
    
//    Del_X_3(L, 2);
//    PrintLinkList(L);
    
//    Del_X_4_D(L, 2);
//    PrintLinkList(L);
    
//    R_Print(L);
    
//    int arr1[20] = {12,4,2,7,22,9};
//    LinkList L2 = ListInit(arr1, 6);
//    PrintLinkList(L2);
//
//    Delete_Min(L2);
//    PrintLinkList(L2);
    
//    Reverse_D(L);
//    PrintLinkList(L);
    
    
    
//    PrintLinkList(L);
    
//    LinkList L2 = L->next;
//    PrintLinkList(L2);
//    LNode *res = Search_1st_Common(L, L2);
//    printf("公共结点 = %d \n", res->data);
    
//    LinkList L1, L2;// = ListInit(arr, 0), L2 = ListInit(arr, 0);
//    splitList(L, L1, L2);
//    PrintLinkList(L1);
//    printf("\n");
//    PrintLinkList(L2);
    
//    int arr1[20] = {1,1,2,2,4,6,6,7,9};
//    LinkList L1 = ListInit(arr1, 9);
//    PrintLinkList(L1);
//
//    Del_Same(L1);
//    PrintLinkList(L1);
    
    
//    int arr1[20] = {2,7,7,9,12,26};
//    LinkList L1 = ListInit(arr1, 6);
//    PrintLinkList(L1);
//    
//    LinkList C = Union(L, L1);
//    PrintLinkList(C);
    
//    int arr1[20] = {1,2};
//    int arr1[20] = {4,6,7};
//    int arr1[20] = {8,9,10};
//    LinkList L1 = ListInit(arr1, 2);
//    PrintLinkList(L1);
//    printf("flag = %d \n", Pattern(L, L1));
    
    
    int arr1[20] = {2,7,7,9,12,26};
    LinkList L1 = ListInit(arr1, 6);
    PrintLinkList(L1);
    
    printf("%d \n", Search_k(L1, 2));

}

void test_dLinklist_q() {
    
//    int arr1[20] = {1,2};
//    int arr1[20] = {1,2,1};
    int arr1[20] = {1,2,2,1};
    DLinklist L1 = DLinklistInit(arr1, 4);
    PrintDLinklist(L1);
//    printf("flag = %d \n", Symmetry(L1));
    
    int arr2[20] = {4,2,4,6,7};
    DLinklist L2 = DLinklistInit(arr2, 5);
    PrintDLinklist(L2);
    
    Connect(L1, L2);
    PrintDLinklist(L1);
}

void test_Linklist_circle_q() {
    int arr1[20] = {4,2,1,3};
    LinkList L1 = ListCircleInit(arr1, 4);
    PrintCircleLinkList(L1);
    
    Del_Min(L1);
}

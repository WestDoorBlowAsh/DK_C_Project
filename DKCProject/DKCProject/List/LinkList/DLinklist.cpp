//
//  DLinklist.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/19.
//  Copyright © 2021 dk. All rights reserved.
//

#include "DLinklist.hpp"

Status PrintDLinklist(DLinklist L) {
    DNode *p = L->next;
    while (p && p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status PrintDLinklist(DLinklist L, bool next) {
    if (next) {
        PrintDLinklist(L);
    } else {
        DNode *p = L;
        while (p) {
            printf("%d ", p->data);
            p = p->prior;
        }
        printf("\n");
    }
    return OK;
}

DLinklist DLinklistInit(int a[], int n) {
    DLinklist L = (DLinklist)malloc(sizeof(DNode));
    L->next = L;
    L->prior = L;
    DNode *s = NULL, *tail = L;
    for (int i = 0; i < n; i++) {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = a[i];

        tail->next = s;
        s->prior = tail;
        
        s->next = L;
        L->prior = s;

        tail = s;
    }
    return L;
}

DLinklist DLinklistInit(int a[], int n, DLinklist &tail) {
    DLinklist L = (DLinklist)malloc(sizeof(DNode));
    L->next = L;
    L->prior = L;
    DNode *s = NULL;
    tail = L;
    for (int i = 0; i < n; i++) {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = a[i];
        tail->next = s;
        s->prior = tail;
        s->next = L;
        L->prior = s;
        tail = s;
    }
    return L;
}


/*
 在第i(1<=i<=L.length+1)个位置插入新元素e.
 
 ps. 也可以通过后插节点后,交换相邻节点数据实现
 */
Status InsertDNode(DLinklist &L, int i, ElemType e) {
//    DNode *pre = GetElem(L, i - 1);
//    if (!pre) {
//        return Error;
//    }
//    DNode *node = (DNode *)malloc(sizeof(DNode));
//    node->data = e;
//    node->next = pre->next;
//    pre->next = node;
    return OK;
}

/*
 删除第i(1<=i<=L.length)个位置元素e.
 */
Status DeleteDNode(DLinklist &L, int i) {
//    DNode *pre = GetElem(L, i - 1);
//    if (!pre) {
//        return Error;
//    }
//    DNode *q = pre->next;
//    pre->next = q->next;
//    free(q);
    return OK;
}

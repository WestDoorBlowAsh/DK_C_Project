//
//  LinkList.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/10.
//  Copyright © 2021 dk. All rights reserved.
//

#include "LinkList.hpp"

Status PrintLinkList(LinkList L) {
    LNode *p = L->next;
    printf("打印链表 ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}


LinkList List_HeadInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s = NULL;
    int x = 0;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s = NULL, *p = L;
    int x = 0;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList ListInit(int a[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s = NULL, *p = L;
    for (int i = 0; i < n; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return L;
}

LNode *GetElem(LinkList L, int i) {
    if (i == 0) {
        return L;
    }
    if (i < 0) {
        return NULL;
    }
    int j = 1;
    LNode *p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

/*
 在第i(1<=i<=L.length+1)个位置插入新元素e.
 
 ps. 也可以通过后插节点后,交换相邻节点数据实现
 */
Status InsertNode(LinkList &L, int i, ElemType e) {
    LNode *pre = GetElem(L, i - 1);
    if (!pre) {
        return Error;
    }
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = e;
    node->next = pre->next;
    pre->next = node;
    return OK;
}

/*
 删除第i(1<=i<=L.length)个位置元素e.
 */
Status DeleteNode(LinkList &L, int i) {
    LNode *pre = GetElem(L, i - 1);
    if (!pre) {
        return Error;
    }
    LNode *q = pre->next;
    pre->next = q->next;
    free(q);
    return OK;
}

int LinkListLength(LinkList L) {
    LNode *p = L->next;
    int i = 0;
    while (p) {
        p = p->next;
        i++;
    }
    return i;
}

LinkList ListCircleInit(int a[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s = NULL, *p = L;
    for (int i = 0; i < n; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = NULL;
        p->next = s;
        p = s;
    }
    s->next = L;
    return L;
}

Status PrintCircleLinkList(LinkList L) {
    LNode *p = L->next;
    while (p && p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

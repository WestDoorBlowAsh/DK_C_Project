//
//  LinkList.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/10.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include <stdio.h>
#include "Tool.hpp"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status PrintLinkList(LinkList L);

LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);
LinkList ListInit(int a[], int n);
LNode *GetElem(LinkList L, int i);
LNode *LocateElem(LinkList L, ElemType e);
Status InsertNode(LinkList &L, int i, ElemType e);
Status DeleteNode(LinkList &L, int i);
int LinkListLength(LinkList L);

// 循环单链表
LinkList ListCircleInit(int a[], int n);
Status PrintCircleLinkList(LinkList L);

#endif /* LinkList_hpp */

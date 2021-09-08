//
//  DLinkList.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/19.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef DLinkList_hpp
#define DLinkList_hpp

#include <stdio.h>
#include "Tool.hpp"

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

Status PrintDLinklist(DLinklist L);
Status PrintDLinklist(DLinklist L, bool next);

DLinklist DLinklistInit(int a[], int n);
DLinklist DLinklistInit(int a[], int n, DLinklist &tail);
Status InsertDNode(DLinklist &L, int i, ElemType e);
Status DeleteDNode(DLinklist &L, int i);

#endif /* DLinkList_hpp */

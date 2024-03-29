//
//  SqList.hpp
//  DKCProject
//
//  Created by 邓凯 on 2020/5/18.
//  Copyright © 2020 dk. All rights reserved.
//

#ifndef SqList_hpp
#define SqList_hpp

#include <stdio.h>
#include "Tool.hpp"

#define SqListMaxSize 50

typedef struct {
    ElemType data[SqListMaxSize];
    int length; // 当前数组长度
    int maxSize;
} SqList;

Status PrintSqList(SqList L);

Status InitList(SqList &L);
Status InitList(SqList &L, int *a, int length);
int Length(SqList &L);
int LocateElem(SqList &L, ElemType e);
ElemType GetElem(SqList &L, int i);
Status ListInsert(SqList &L, int i, ElemType e);
Status ListDelete(SqList &L, int i, ElemType &e);
bool Empty(SqList L);
Status DestroyList(SqList &L);

#endif /* SqList_hpp */


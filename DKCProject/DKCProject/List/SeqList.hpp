//
//  SeqList.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/3/30.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef SeqList_hpp
#define SeqList_hpp

#include <stdio.h>

#define SeqListMaxSize 5

typedef int ElemType;
typedef struct {
    ElemType *data;
    int maxSize, length;
} SeqList;

enum Status {
    OK = 1,
    Error = -1
};

Status InitList(SeqList &L);
Status InitList(SeqList &L, int *a, int length);
int Length(SeqList &L);
int LocateElem(SeqList &L, ElemType e);
ElemType GetElem(SeqList &L, int i);
Status ListInsert(SeqList &L, int i, ElemType e);
Status ListDelete(SeqList &L, int i, ElemType &e);
Status PrintList(SeqList L);
bool Empty(SeqList L);
Status DestroyList(SeqList &L);

#endif /* SeqList_hpp */

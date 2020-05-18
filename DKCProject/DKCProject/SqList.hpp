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

#define SqListMaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[SqListMaxSize];
    int length;
} SqList;

#define InitSize 100
typedef struct {
    ElemType *data;
    int maxSize, length;
} SeqList;

enum Status {
    OK = 1,
    Error = -1
};

Status InitList(SqList &L);
int Length(SqList &L);
int LocateElem(SqList &L, ElemType e);
Status GetElem(SqList &L, int i);
Status ListInsert(SqList &L, int i, ElemType e);
Status ListDelete(SqList &L, int i, ElemType &e);
Status PrintList(SqList L);
bool Empty(SqList L);
Status DestroyList(SqList &L);

Status InitSeqList(SeqList &L);


#endif /* SqList_hpp */

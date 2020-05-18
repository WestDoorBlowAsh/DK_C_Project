//
//  SqList.cpp
//  DKCProject
//
//  Created by 邓凯 on 2020/5/18.
//  Copyright © 2020 dk. All rights reserved.
//

#include "SqList.hpp"


Status InitList(SqList &L) {
    L.length = 0;
    return Success;
}

int Length(SqList &L) {
    return L.length;
}

int LocateElem(SqList &L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return Fail;
}
//int GetElem(SqList &L, int i);
//Status ListInsert(SqList &L, int i, ElemType e);
//Status ListDelete(SqList &L, int i, ElemType &e);
//Status PrintList(SqList L);
//bool Empty(SqList L);
//Status DestroyList(SqList &L);


Status InitSeqList(SeqList &L) {
    L.data = new ElemType[InitSize];
    L.maxSize = InitSize;
    L.length = 0;
    return Success;
}

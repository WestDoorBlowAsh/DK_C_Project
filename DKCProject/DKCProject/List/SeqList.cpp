//
//  SeqList.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/3/30.
//  Copyright © 2021 dk. All rights reserved.
//

#include "SeqList.hpp"
#include <stdlib.h>

Status InitList(SeqList &L) {
    L.length = 0;
    return OK;
}

Status InitList(SeqList &L, int *a, int length) {
    L.data = (ElemType *)malloc(sizeof(ElemType) * SeqListMaxSize);
    L.maxSize = SeqListMaxSize;
    if (!L.data) {
        return Error;
    }
    L.length = length;
    for (int i = 0; i < length; i++) {
        L.data[i] = a[i];
    }
    return OK;
}

int Length(SeqList &L) {
    return L.length;
}

int LocateElem(SeqList &L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i;
        }
    }
    return Error;
}

ElemType GetElem(SeqList &L, int i) {
    if (i < 0 || i > L.length - 1) {
        return NULL;
    }
    return L.data[i];
}

Status ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 0 || i > L.length) {
        return Error;
    }
    if (L.length >= SeqListMaxSize) {
        int maxSize = L.length * 2 + 1;
        L.maxSize = maxSize;
        L.data = (ElemType *)realloc(L.data, sizeof(ElemType) * maxSize);
        printf("重新分配数组\n");
    }
    for (int j = L.length - 1; j >= i; j--) {
        L.data[j+1] = L.data[j];
    }
    L.data[i] = e;
    L.length++;
    return OK;
}

Status ListDelete(SeqList &L, int i, ElemType &e) {
    if (i < 0 || i > L.length - 1) {
        return Error;
    }
    e = L.data[i];
    for (int j = i; j < L.length - 1; j++) {
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return OK;
}

Status PrintList(SeqList L) {
    if (L.length == 0) {
        printf("SeqList 为空");
    }
    for (int i = 0; i < L.length; i++) {
//        printf("第 %d 个元素：%d\n", i, L.data[i]);
        printf("%d ", L.data[i]);
    }
    printf("\n");
    printf("L.length 长度: %d\n", L.length);
    printf("L.maxSize 长度: %d\n", L.maxSize);
    printf("\n");
    return OK;
}

bool Empty(SeqList L) {
    L.length = 0;
    return true;
}

Status DestroyList(SeqList &L) {
    free(L.data);
    L.length = 0;
    L.maxSize = 0;
    return OK;
}

Status InitSeqList(SeqList &L) {
    L.data = new ElemType[SeqListMaxSize];
    L.maxSize = SeqListMaxSize;
    L.length = 0;
    return OK;
}

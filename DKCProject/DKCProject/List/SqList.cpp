//
//  SqList.cpp
//  DKCProject
//
//  Created by 邓凯 on 2020/5/18.
//  Copyright © 2020 dk. All rights reserved.
//

#include "SqList.hpp"
#include <stdlib.h>

Status InitList(SqList &L) {
    L.length = 0;
    return OK;
}

Status InitList(SqList &L, int *a, int length) {
    L.length = length;
    for (int i = 0; i < length; i++) {
        L.data[i] = a[i];
    }
    return OK;
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
    return Error;
}

ElemType GetElem(SqList &L, int i) {
    if (i < 0 || i > L.length - 1) {
        return NULL;
    }
    return L.data[i];
}

Status ListInsert(SqList &L, int i, ElemType e) {
    if (i < 0 || i > L.length) {
        return Error;
    }
    for (int j = L.length - 1; j >= i; j--) {
        L.data[j+1] = L.data[j];
    }
    L.data[i] = e;
    L.length++;
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
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

Status PrintList(SqList L) {
    if (L.length == 0) {
        printf("SqList 为空");
    }
    for (int i = 0; i < L.length; i++) {
//        printf("第 %d 个元素：%d\n", i, L.data[i]);
        printf("%d ", L.data[i]);
    }
    printf("\n");
    printf("L.length 长度: %d\n", L.length);
    printf("\n");
    return OK;
}

bool Empty(SqList L) {
    L.length = 0;
    return true;
}

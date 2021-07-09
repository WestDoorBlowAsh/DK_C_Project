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
    L.maxSize = SqListMaxSize;
    return OK;
}

Status InitList(SqList &L, int *a, int length) {
    if (length > SqListMaxSize) {
        return Error;
    }
    L.length = length;
    for (int i = 0; i < length; i++) {
        L.data[i] = a[i];
    }
    L.maxSize = SqListMaxSize;
    return OK;
}

int Length(SqList &L) {
    return L.length;
}

int LocateElem(SqList &L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i+1;     // 下标为i的元素值等于e, 返回其位序i+1
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

/*
 在第i(1<=i<=L.length+1)个位置插入新元素e.
 */
Status ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return Error;
    }
    if (L.length >= SqListMaxSize) {
        return Error;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return OK;
}

/*
 删除第i(1<=i<=L.length+1)个位置元素e.
 */
Status ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return Error;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++) {
        L.data[j-1] = L.data[j];
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
    return OK;
}

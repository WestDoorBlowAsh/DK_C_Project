//
//  SqStack.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/8.
//  Copyright © 2021 dk. All rights reserved.
//

#include "SqStack.hpp"

// 从 栈底 打印元素
Status PrintSqStack(SqStack S) {
    if (S.top < 0) {
        return Error;
    }
    int n = 0;
    printf("打印栈 ");
    while (n <= S.top) {
        printf("%d ", S.data[n++]);
    }
    printf("\n");
    return OK;
}

void InitStack(SqStack &S) {
    S.top = -1;
}

Status InitStack(SqStack &S, int *a, int length) {
    S.top = -1;
    int index = 0;
    while (length--) {
        Push(S, a[index++]);
    }
    return OK;
}

bool StackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    return false;
}

Status Push(SqStack &S, ElemType x) {
    if (S.top == SqStackMaxSize - 1) {
        return Error;
    }
    S.data[++S.top] = x;
    return OK;
}

Status Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) {
        return Error;
    }
    x = S.data[S.top--];
    return OK;
}

Status GetTop(SqStack S, ElemType &x) {
    if (S.top == -1) {
        return Error;
    }
    x = S.data[S.top];
    return OK;
}


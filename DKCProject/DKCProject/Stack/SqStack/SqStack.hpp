//
//  SqStack.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/8.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef SqStack_hpp
#define SqStack_hpp

#include <stdio.h>
#include "Tool.hpp"

#define SqStackMaxSize 50

typedef struct {
    ElemType data[SqStackMaxSize];
    int top; // 当前数组长度
} SqStack;

Status PrintSqStack(SqStack S);

void InitStack(SqStack &S);
Status InitStack(SqStack &S, int *a, int length);
bool StackEmpty(SqStack S);
Status Push(SqStack &S, ElemType x);
Status Pop(SqStack &S, ElemType &x);
Status GetTop(SqStack S, ElemType &x);
Status DestoryStack(SqStack &S);

#endif /* SqStack_hpp */

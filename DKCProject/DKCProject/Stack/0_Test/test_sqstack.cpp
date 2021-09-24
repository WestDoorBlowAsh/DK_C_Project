//
//  test_sqstack.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/8.
//  Copyright © 2021 dk. All rights reserved.
//

#include "test_sqstack.hpp"

void test_sqstack() {
    
    SqStack S;
    
    int arr[20] = {4,2,6,3,7};
    InitStack(S, arr, 5);
    PrintSqStack(S);
    
    printf("栈是否为空 %d\n", StackEmpty(S));
    
    int x = 100;
//    Push(S, x);
//    PrintSqStack(S);
    
    Pop(S, x);
    printf("出栈元素 %d\n", x);
    PrintSqStack(S);
    
    GetTop(S, x);
    printf("栈顶元素 %d\n", x);
}


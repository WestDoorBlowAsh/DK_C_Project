//
//  test_sqstack.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/8.
//  Copyright © 2021 dk. All rights reserved.
//

#include "test_sqstack.hpp"
#include "Stack_Q.hpp"


void test_sqstack_q() {
    
//    char str1[] = "IOIIOIOO";
//    printf("%d\n", isIOLegal(str1, sizeof(str1)));
//    char str2[] = "IOOIOIIO";
//    printf("%d\n", isIOLegal(str2, sizeof(str2)));
//    char str3[] = "IIIOIOIO";
//    printf("%d\n", isIOLegal(str3, sizeof(str3)));
//    char str4[] = "IIIOOIOO";
//    printf("%d\n", isIOLegal(str4, sizeof(str4)));
//    char str5[] = "IOII";
//    printf("%d\n", isIOLegal(str5, sizeof(str5)));
    
    
    int arr[20] = {1,2,4,4,2,1};
    LinkList L = ListInit(arr, 6);
    PrintLinkList(L);
    printf("%d \n", dc_D(L));
    
    L = ListInit(arr, 5);
    PrintLinkList(L);
    printf("%d \n", dc_D(L));
    
    L = ListInit(arr, 1);
    PrintLinkList(L);
    printf("%d \n", dc_D(L));
    
    
    
//    (L);
    
}

void test_sqstack() {
    
    SqStack S;
    
    InitStack(S);
    PrintSqStack(S);
    
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


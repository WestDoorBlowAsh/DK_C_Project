//
//  Stack_Q.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/24.
//  Copyright © 2021 dk. All rights reserved.
//

#include "Stack_Q.hpp"

// 入栈出栈序列是否合法
bool isIOLegal(char *str, int len) {
    
//    char *str = "IOIIOIOO";

//    int len = sizeof(str) / sizeof(char);
    len = len - 1;
    printf("%s %d\n", str, len);
    if (len % 2 != 0) {
        return false;
    }
    
    int count = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch == 'I') {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    
    if (count == 0) {
        return true;
    }
    return false;
}

// 单链表是否对称
bool dc(LinkList L, int n) {
    int i;
    char s[n/2];
    LNode *p = L->next;
    
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    if (n % 2 == 1) {
        p = p->next;
    }
    while (p != NULL && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1) {
        return true;
    } else {
        return false;
    }
}

bool dc_D(LinkList L) {
    
    LNode *p = L->next, *q = L->next;
    
    SqStack S;
    InitStack(S);
    
    while (q->next) {
        Push(S, p->data);
        
        p = p->next;
        q = q->next;
        if (q->next) {
            q = q->next;
        }
    }
    
    PrintSqStack(S);
    
    while (!StackEmpty(S)) {
        ElemType data;
        Pop(S, data);
        if (data != p->data) {
            return false;
        }
        p = p->next;
    }
    
    return true;
}

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

// 括号匹配
bool BracketsCheck(char *str) {
    SqStack S;
    InitStack(S);
    int i = 0;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
                Push(S, str[i]);
                break;
            case ')':
                ElemType x;
                Pop(S, x);
                if (x != '(') {
                    return false;
                }
            default:
                break;
        }
        i++;
    }
    if (StackEmpty(S)) {
        return true;
    }
    return false;
}

// 字符串中 S 弄到 H 之前
void Train_Arrange(char *train) {
    SqStack S;
    InitStack(S);
    
    char *p = train, *q = train;
    ElemType c;
    while (*p) {
        if (*p == 'H') {
            Push(S, *p);
        } else {
            *(q++) = *p;
        }
        p++;
    }
    while (!StackEmpty(S)) {
        Pop(S, c);
        *(q++) = c;
    }
}

// 栈实现递归函数
double p(int n, int x) {
    struct stack {
        int no;
        double val;
    } st[SqStackMaxSize];
    
    int top = -1;
    for (int i = n; i >= 2; i++) {
        top++;
        st[top].no = i;
    }
    int fv1 = 1, fv2 = 2 * x;
    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0) {
        return fv1;
    }
    return fv2;
}


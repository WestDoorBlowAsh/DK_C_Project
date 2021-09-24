//
//  LiStack.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/13.
//  Copyright © 2021 dk. All rights reserved.
//

#include "LiStack.hpp"


ShareStack s;

// i为栈号
int push(int i, ElemType x) {
    if (i < 0 || i > 1) {
        printf("栈号不对\n");
        exit(0);
    }
    if (s.top[1] - s.top[0] == 1) {
        printf("栈满\n");
        return 0;
    }
    switch (i) {
        case 0:
            s.stack[++s.top[0]] = x;
            return 1;
            break;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
            break;
    }
    return 1;
}

ElemType pop(int i) {
    if (i < 0 || i > 1) {
        printf("栈号不对\n");
        exit(0);
    }
    if (s.top[0] == -1 || s.top[1] == maxsize) {
        printf("栈空\n");
        return -1;
    }
    switch (i) {
        case 0:
            return s.stack[s.top[0]--];
            break;
        case 1:
            return s.stack[s.top[1]++];
            break;
    }
    return 0;
}

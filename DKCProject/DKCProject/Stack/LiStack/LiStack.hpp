//
//  LiStack.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/13.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef LiStack_hpp
#define LiStack_hpp

#include <stdio.h>
#include "Tool.hpp"

typedef LinkNode LiStack;

#define maxsize 100
typedef struct {
    ElemType stack[maxsize];
    int top[2];
} ShareStack;   // 共享栈

#endif /* LiStack_hpp */

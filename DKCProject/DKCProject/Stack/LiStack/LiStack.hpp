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

typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} *LiStack;

#endif /* LiStack_hpp */

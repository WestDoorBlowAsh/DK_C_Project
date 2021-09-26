//
//  SqQueue.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/24.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef SqQueue_hpp
#define SqQueue_hpp

#include <stdio.h>

#include "Tool.hpp"

#define SqQueueMaxSize 5

typedef struct {
    ElemType data[SqQueueMaxSize];
    // front 指向队头元素, rear 指向队尾元素的下一个位置
    int front, rear;    // 队头指针,队尾指针
    
    /**
     *表示元素个数.
     *队空 Q.size == 0
     *队满 Q.size == maxSize
     *两种情况都有 Q.front == Q.rear
     */
    int size;
    
    /**
     *tag == 0时, 若因删除导致 Q.front == Q.rear, 则为队空
     *tag == 1时, 若因插入导致 Q.front == Q.rear, 则为队满
     */
    int tag;
    
} SqQueue;

Status PrintSqQueue(SqQueue Q);

void InitQueue(SqQueue &Q);
Status InitQueue(SqQueue &Q, int *a, int length);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType &x);
bool GetHead(SqQueue Q, ElemType &x);

#endif /* SqQueue_hpp */

//
//  SqQueue.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/24.
//  Copyright © 2021 dk. All rights reserved.
//

#include "SqQueue.hpp"

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

//Status InitQueue(SqQueue &Q, int *a, int length);

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool isFull(SqQueue Q) {
    return (Q.rear + 1) % SqQueueMaxSize == Q.front;
}

int QueueCount(SqQueue Q) {
    return (Q.rear - Q.front + SqQueueMaxSize) % SqQueueMaxSize;
}

// 入队
bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % SqQueueMaxSize == Q.front) {
        printf("队列为满\n");
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % SqQueueMaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front) {
        printf("队列为空\n");
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % SqQueueMaxSize;
    return true;
    
}

bool GetHead(SqQueue Q, ElemType &x);






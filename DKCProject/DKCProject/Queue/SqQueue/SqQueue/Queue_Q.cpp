//
//  Queue_Q.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/9/26.
//  Copyright © 2021 dk. All rights reserved.
//

#include "Queue_Q.hpp"
#include "SqStack.hpp"

/**
 *带有标志位的入队出队
 *tag = 0 时 队列为空
 *tag = 1 时 队列为满
 */
// 入队
bool EnTagQueue(SqQueue &Q, ElemType x) {
    if (Q.rear == Q.front && Q.tag == 1) {
        printf("队列为满\n");
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % SqQueueMaxSize;
    Q.tag = 1;
    return true;
}

bool DeTagQueue(SqQueue &Q, ElemType x) {
    if (Q.rear == Q.front && Q.tag == 0) {
        printf("队列为空\n");
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % SqQueueMaxSize;
    Q.tag = 0;
    return true;
}

// 利用栈将队列元素逆置
void Inverser(SqQueue &Q, SqStack S) {
    ElemType x;
//    SqStack S;
//    InitStack(S);
    while (!QueueEmpty(Q)) {
        DeQueue(Q, x);
        Push(S, x);
    }
    while (!StackEmpty(S)) {
        Pop(S, x);
        EnQueue(Q, x);
    }
}

// 两个栈模拟队列
bool StackOverflow(SqStack S) {
    return false;
}

bool EnStackQueue(SqStack &S1, SqStack &S2, ElemType x) {
    
    if (StackOverflow(S1) && !StackEmpty(S2)) {
        return false;
    }
    ElemType ele;
    if (StackOverflow(S1) && StackEmpty(S2)) {
        while (!StackEmpty(S1)) {
            Pop(S1, ele);
            Push(S2, ele);
        }
    }
    Push(S1, x);
    return true;
}

bool DeStackQueue(SqStack &S1, SqStack &S2, ElemType x) {
    if (StackEmpty(S1) && StackEmpty(S2)) {
        return false;
    }
    ElemType ele;
    if (StackEmpty(S2)) {
        while (!StackEmpty(S1)) {
            Pop(S1, ele);
            Push(S2, ele);
        }
    }
    Pop(S2, ele);
    x = ele;
    return true;
}

bool StackQueueEmpty(SqStack &S1, SqStack &S2, ElemType x) {
    if (StackEmpty(S1) && StackEmpty(S2)) {
        return true;
    }
    return false;
}

// 渡口管理
void manager() {
    SqQueue queue;  // 渡船
    SqQueue queueK; // 客车
    SqQueue queueH; // 货车
    
    int i = 0, j = 0;
    ElemType x;
    
    while (j < 10) {
        if (!QueueEmpty(queueK) && i < 4) {
            DeQueue(queueK, x);
            EnQueue(queue, x);
            i++;
            j++;
        } else if (!QueueEmpty(queueH) && i == 4) {
            DeQueue(queueH, x);
            EnQueue(queue, x);
            i = 0;
            j++;
        } else {
            while (j < 10 && i < 4 && !QueueEmpty(queueH)) {
                DeQueue(queueH, x);
                EnQueue(queue, x);
                j++;
                i++;
            }
            i = 0;
            
        }
        if (QueueEmpty(queueK) && QueueEmpty(queueH)) {
            break;
        }
    }
}

//
//  SqList_Q.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/9.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef SqList_Q_hpp
#define SqList_Q_hpp

#include <stdio.h>
#include "SqList.hpp"

bool Del_Min(SqList &L, ElemType &e);
void Reverse(SqList &L);
bool Del_x_1(SqList &L, ElemType e);
bool Del_x_2(SqList &L, ElemType e);
bool Del_X_D(SqList &L, ElemType e);
bool Del_s_t_D(SqList &L, int s, int t);
bool Del_s_t2(SqList &L, int s, int t);
bool Del_s_t_D2(SqList &L, int s, int t);
bool Del_s_t(SqList &L, int s, int t);
bool Del_same_D(SqList &L);
bool Merge(SqList &L1, SqList &L2, SqList &L);
void Exchange(int A[], int m, int n, int arraySize);
void SearchExchangeInsert_D(SqList &L, int x);
void SearchExchangeInsert(ElemType A[], ElemType x);



#endif /* SqList_Q_hpp */


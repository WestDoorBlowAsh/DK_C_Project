//
//  LinkList_Q.hpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/19.
//  Copyright © 2021 dk. All rights reserved.
//

#ifndef LinkList_Q_hpp
#define LinkList_Q_hpp

#include <stdio.h>
#include "LinkList.hpp"
#include "DLinklist.hpp"

void Del_X_3(LinkList &L, ElemType x);
void Del_X_4_D(LinkList &L, ElemType x);
void Del_X_1(LinkList &L, ElemType x);
void Del_X_2(LinkList &L, ElemType x);
void R_Print(LinkList L);
void Delete_Min(LinkList &L);
void Delete_Min_D(LinkList &L);
void Reverse_1(LinkList &L);
LNode *Search_1st_Common(LinkList L1, LinkList L2);
void Min_Delete(LinkList &L);
void DisCreat_1_D(LinkList &L, LinkList &L1, LinkList &L2);
LinkList DisCreat_1(LinkList &A);
void DisCreat_2_D(LinkList &C, LinkList &L1, LinkList &L2);
void Del_Same(LinkList &L);
void Del_Same_D(LinkList &L);
void MergeList(LinkList &La, LinkList &Lb);
LinkList Get_Common_D(LinkList &La, LinkList &Lb);
LinkList Union(LinkList &La, LinkList &Lb);
bool Pattern(LinkList &La, LinkList &Lb);
bool Symmetry(DLinklist L);
DLinklist Connect(DLinklist &h1, DLinklist &h2);
void Del_Min(LinkList &L);
bool Search_k(LinkList &L, int k);
bool Search_k_D(LinkList &L, int k);

#endif /* LinkList_Q_hpp */

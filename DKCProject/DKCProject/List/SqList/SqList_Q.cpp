//
//  SqList_Q.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/9.
//  Copyright © 2021 dk. All rights reserved.
//

#include "SqList_Q.hpp"
#include "SqList.hpp"

// 删除最小值元素
bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0) {
        printf("顺序表为空\n");
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++) {
        if (value > L.data[i]) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 逆置顺序表
void Reverse(SqList &L) {
    ElemType e;
    for (int i = 0; i < L.length / 2; i++) {
        e = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = e;
    }
}

bool Reverse_D(SqList &L) {
    if (L.length <= 1) {
        return true;
    }
    for (int i = 0, j = L.length - 1; i < j; i++, j--) {
        ElemType e = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = e;
    }
    return true;
}

// 删除所有值为x
bool Del_x_1(SqList &L, ElemType e) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != e) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

bool Del_x_2(SqList &L, ElemType e) {
    int i = 0, k = 0;
    while (i < L.length) {
        if (L.data[i] == e) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
        i++;
    }
    L.length -= k;
    return true;
}

bool Del_X_D(SqList &L, ElemType e) {
    int i = 0, j = 0;
    while (j < L.length) {
        while (L.data[j] == e) {
            j++;
            L.length--;
        }
        L.data[i] = L.data[j];
        i++;
        j++;
    }
    
    return true;
}

// 有序顺序表删除[s,t]之间的所有元素
bool Del_s_t_D(SqList &L, int s, int t) {
    if (L.length == 0 || s >= t) {
        return false;
    }
    int j = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] >= s && j < 0) {
            j = i;
        }
        if (L.data[i] > t && j >= 0) {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
    return true;
}

bool Del_s_t2(SqList &L, int s, int t) {
    int i, j;
    if (s >= t || L.length == 0) {
        return false;
    }
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    if (i >= L.length) {
        return false;
    }
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}

// 顺序表删除[s,t]之间的所有元素
bool Del_s_t_D2(SqList &L, int s, int t) {
    if (s >= t || L.length == 0) {
        return false;
    }
    int i = 0, j = 0;
    for (; j < L.length; j++) {
        if (L.data[j] < s || L.data[j] > t) {
            L.data[i] = L.data[j];
            i++;
        }
    }
    L.length = i;
    return true;
}

bool Del_s_t(SqList &L, int s, int t) {
    if (s >= t || L.length == 0) {
        return false;
    }
    int i, k = 0;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

// 有序顺序表删除所有重复的的元素
bool Delete_same_D(SqList &L) {
    if (L.length <= 1) {
        return false;
    }
    int i = 0, j = 1;
    for (; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {
            ++i;
            L.data[i] = L.data[j];
        }
    }
    L.length = i+1;
    return true;
}

bool Delete_same(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i+1;
    return true;
}

// 合并两个顺序表
bool Merge(SqList &L1, SqList &L2, SqList &L) {
    if (L1.length + L2.length > L.maxSize) {
        return false;
    }
    
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {
            L.data[k++] = L1.data[i++];
        } else {
            L.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) {
        L.data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        L.data[k++] = L2.data[j++];
    }
    L.length = k;
    return true;
}

// A[m+n] 包括 a1...am, b1...bn, 将 b 放在 a 前面.
void Reverse(int A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize) {
        return ;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++) {
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void Exchange(int A[], int m, int n, int arraySize) {
    Reverse(A, 0, m+n-1, arraySize);
    Reverse(A, 0, n-1, arraySize);
    Reverse(A, n, m+n-1, arraySize);
}

// 最少时间(折半查找)有序顺序表查找x, 找到与后继元素交换, 找不到插入x保持有序
void SearchExchangeInsert_D(SqList &L, int x) {
    int temp = 0;
    int flag = false;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x && i + 1 < L.length) {
            temp = L.data[i+1];
            L.data[i+1] = L.data[i];
            L.data[i] = temp;
            break;
        }
        if (L.data[i] > x) {
            temp = L.data[i];
            L.data[i] = x;
            x = temp;
            flag = true;
        }
    }
    if (flag) {
        L.data[L.length] = temp;
        L.length++;
    }
}


void SearchExchangeInsert(ElemType A[], ElemType x) {
    
}

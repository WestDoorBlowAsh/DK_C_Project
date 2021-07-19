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


void SearchExchangeInsert(ElemType A[], int n, ElemType x) {
    int low = 0, high = n - 1, mid = 0, i;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == x) {
            break;
        } else if (A[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (A[mid] == x && mid != n - 1) {
        int temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    if (low > high) {
        for (i = n - 1; i > high; i--) {
            A[i+1] = A[i];
        }
        A[i+1] = x;
    }
}

// 一维数组左移p个位置
void Reverse_D(int a[], int left, int right) {
    int mid = (right + left) / 2;
    for (int i = 0; i <= mid - left; i++) {
        int temp = a[left + i];
        a[left + i] = a[right - i];
        a[right - i] = temp;
    }
}

void Converse_D(int a[], int n, int p) {
    Reverse_D(a, 0, n-1);
    Reverse_D(a, 0, n-p-1);
    Reverse_D(a, n-p, n-1);
}

void Reverse(int a[], int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        int temp = a[from + i];
        a[from + i] = a[to - i];
        a[to - i] = temp;
    }
}

void Converse(int a[], int n, int p) {
    Reverse_D(a, 0, p-1);
    Reverse_D(a, p, n-1);
    Reverse_D(a, 0, n-1);
}

// 找到两个等长升序数组共同的中位数
int M_search_D(int a[], int b[], int n) {
    int i = 0, j = 0, k = 0, mid = 0;
    while (i < n && j < n && k < n) {
        if (a[i] > b[j]) {
            mid = b[j];
            j++;
        } else {
            mid = a[i];
            i++;
        }
        k++;
    }
    return mid;
}

int M_search(int a[], int b[], int n) {
    int s1 = 0, d1 = n-1, s2 = 0, d2 = n-1, m1 = 0, m2 = 0;
    while (s1 != d1 && s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (a[m1] == b[m2]) {
            return a[m1];
        } else if (a[m1] < b[m2]) {
            if ((s1 + d1) % 2 == 0) {   // 偶数
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                s2 = m2;
                d1 = m1;
            } else {
                s2 = m2 + 1;
                d1 = m1;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}

// 数组中找到出现次数最多的数
int Majority(int a[], int n) {
    if (n == 0) {
        return -1;
    }
    int main = a[0], count = 1, i;
    for (i = 1; i < n; i++) {
        if (a[i] == main) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                main = a[i];
                count = 1;
            }
        }
    }
    for (i = 0, count = 0; i < n; i++) {
        if (a[i] == main) {
            count++;
        }
    }
    if (count > n / 2) {
        return main;
    }
    return -1;
}

// 数组中找到最小正整数
int findMissMin(int a[], int n) {
    int i, *B;
    B = (int *)malloc(sizeof(int) * n);
    memset(B, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] <= n) {
            B[a[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0) {
            break;
        }
    }
    
    return i+1;
}

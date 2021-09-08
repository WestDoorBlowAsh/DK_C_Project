//
//  LinkList_Q.cpp
//  DKCProject
//
//  Created by 邓凯 on 2021/7/19.
//  Copyright © 2021 dk. All rights reserved.
//

#include "LinkList_Q.hpp"

// 单链表删除x
void Del_X_3(LinkList &L, ElemType x) {
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        LNode *p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else {
        Del_X_3(L->next, x);
    }
}

void Del_X_4_D(LinkList &L, ElemType x) {
    LNode *pre = L;
    LNode *p = L->next;
    LNode *q = p;
    
    while (p) {
        if (q->data == x) {
            pre->next = q->next;
            free(q);
        }
        pre = p;
        p = p->next;
        q = p;
    }
}

// 遍历链表删除结点
void Del_X_1(LinkList &L, ElemType x) {
    LNode *pre = L;
    LNode *p = L->next;
    LNode *q;
    
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 符合要求的结点链接到 L 后
void Del_X_2(LinkList &L, ElemType x) {
    LNode *pre = L;
    LNode *p = L->next;
    LNode *q;
    
    while (p != NULL) {
        if (p->data != x) {
            pre->next = p;
            pre = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(p);
        }
    }
    pre->next = NULL;
}

// 倒置打印单链表
void R_Print(LinkList L) {
    if (L->next != NULL) {
        R_Print(L->next);
    }
    // 判断带头结点链表为空
    if (L->next != NULL) {
        printf("%d ", L->next->data);
    }
}

// 单链表删除最小值
void Delete_Min_D(LinkList &L) {
    LNode *minNodePre = L;
    LNode *p = minNodePre->next;
    if (!p) {
        return;
    }
    ElemType min = p->data;
    while (p) {
        if (p->next != NULL && p->next->data < min) {
            min = p->next->data;
            minNodePre = p;
        }
        p = p->next;
    }
    LNode *q = minNodePre->next;
    minNodePre->next = q->next;
    free(q);
}

void Delete_Min(LinkList &L) {
    LNode *pre = L;
    LNode *p = L->next;
    LNode *minpre = pre;
    LNode *minp = p;
    
    while (p) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

// 倒置单链表
void Reverse_1(LinkList &L) {
    LNode *p = L->next, *r;
    L->next = NULL;
    while (p) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

void Reverse_2(LinkList &L) {
    LNode *p = L->next;
    LNode *r = p ->next, *pre;
    
    p->next = NULL;
    while (r) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    
    L->next = p;
}

// 排序单链表 O(n^2)
void Sort(LinkList &L) {
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

// 单链表删除介于2值之间的所有元素
void RangeDelete_D(LinkList &L, int x, int y) {
    LNode *p = L->next;
    LNode *pre = L;
    while (p) {
        if (p->data > x && p->data < y) {
            LNode *q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 找到两个链表的公共结点
LNode *Search_1st_Common_D(LinkList L1, LinkList L2) {
    int len1 = LinkListLength(L1);
    int len2 = LinkListLength(L2);
    
    LNode *p = L1->next, *q = L2->next;
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff > 0) {
            p = p->next;
            diff--;
        }
    } else {
        int diff = len2 - len1;
        while (diff > 0) {
            q = q->next;
            diff--;
        }
    }
    
    while (p != NULL) {
        if (p == q) {
            return p;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    return NULL;
}

LNode *Search_1st_Common(LinkList L1, LinkList L2) {
    int len1 = LinkListLength(L1);
    int len2 = LinkListLength(L2), dist;
    LinkList longList, shortList;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {
        longList = longList->next;
    }
    while (longList != NULL) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

// head, data, next 递增输出元素并释放空间
void Min_Delete(LinkList &head) {
    LNode *p, *pre, *q;
    while (head->next != NULL) {
        pre = head;
        p = pre->next;
        while (p->next != NULL) {
            if (p->next->data < pre->next->data) {
                pre = p;
            }
            p = p->next;
        }
        q = pre->next;
        printf("%d ", q->data);
        pre->next = q->next;
        free(q);
    }
    free(head);
}

// 链表拆分为 奇数序号链表 和 偶数序号链表
void DisCreat_1_D(LinkList &L, LinkList &L1, LinkList &L2) {
    LNode *p = L, *p1 = L1, *p2 = L2;
    int i = 0;
    while (p->next) {
        if (i % 2) {
            p2->next = p->next;
            p2 = p2->next;
        } else {
            p1->next = p->next;
            p1 = p1->next;
        }
        p = p->next;
        i++;
    }
    p2->next = NULL;
    p1->next = NULL;
}

LinkList DisCreat_1(LinkList &A) {
    int i = 0;
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;
    
    LNode *p = A->next;
    A->next = NULL;
    while (p) {
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}

// 链表拆分 [a1,b1,a2,b2,...,an,bn] 为 [a1,a1,...,an], [bn,...,b2,b1]
void DisCreat_2_D(LinkList &C, LinkList &A, LinkList &B) {
    LNode *p = C->next;
    int i = 0;
    
    A = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    
    LNode *ra = A, *rb = B, *q;
    
    while (p) {
        q = p->next;
        if (i % 2 == 0) {
            ra->next = p;
            ra = p;
        } else {
            p->next = rb->next;
            rb->next = p;
        }
        p = q;
        i++;
    }
    ra->next = NULL;
}

LinkList DisCreat_2(LinkList &A) {
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q = NULL;
    LNode *ra = A;
    while (p) {
        ra->next = p;
        ra = p;
        p = p->next;
        if (p != NULL) {
            q = p->next;
        }
        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = NULL;
    
    return B;
}

// 有序递增单链表删除相同元素
void Del_Same_D(LinkList &L) {
    LNode *p = L->next, *pre = L, *q = p->next;
    ElemType temp = p->data;
    while (p) {
        
        if (temp == p->data && p != L->next) {
            q = p->next;
            pre->next = p->next;
            free(p);
            p = q;
        } else {
            temp = p->data;
            pre = p;
            p = p->next;
        }
    }
}

void Del_Same(LinkList &L) {
    LNode *p = L->next, *q;
    if (p == NULL) {
        return;
    }
    while (p->next != NULL) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

// 两个元素递增单链表合成一个元素递减单链表
void MergeList(LinkList &La, LinkList &Lb) {
    LNode *r, *pa = La->next, *pb = Lb->next;
    La->next = NULL;
    
    while (pa && pb) {
        if (pa->data <= pb->data) {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa) {
        pb = pa;
    }
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

// 两个单链表的公共元素产生新链表
LinkList Get_Common_D(LinkList &La, LinkList &Lb) {
    LNode *pa = La->next, *pb = Lb->next;
    LinkList C = (LinkList)malloc(sizeof(LNode));
    C->next = NULL;
    LNode *pc = C;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            LNode *n = (LNode *)malloc(sizeof(LNode));
            n->data = pa->data;
            n->next = NULL;
            pc->next = n;
            pc = n;
            pa = pa->next;
            pb = pb->next;
        }
    }
    return C;
}

// 交集
LinkList Union_D(LinkList &La, LinkList &Lb) {
    LNode *pa = La->next, *pb = Lb->next, *p = La;
    
    while (pa && pb) {
        if (pa->data < pb->data) {
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            p->next = pa;
            p = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }
    p->next = NULL;
    return La;
}

LinkList Union(LinkList &La, LinkList &Lb) {
    LNode *pa = La->next, *pb = Lb->next, *p = La, *u;
    
    while (pa && pb) {
        if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else if (pa->data > pb->data) {
            u = pb;
            pb = pb->next;
            free(u);
        } else {
            p->next = pa;
            p = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    p->next = NULL;
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    free(Lb);
    return La;
}

bool Pattern(LinkList &La, LinkList &Lb) {
    LNode *pa = La, *pb = Lb, *pre = pa;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
        } else {
            pre = pre->next;
            pa = pre;
            pb = Lb;
        }
    }
    return pb == NULL;
}

// 循环双链表是否对称
bool Symmetry(DLinklist L) {
    DNode *p = L->next, *q = L->prior;
    // 不能写成 p->next != q, 例 1,2,3,1 会出现中间两个结点不判断就跳出循环了
    while (p != q && q->next != p) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return false;
        }
    }
    return true;
}

DLinklist Connect(DLinklist &h1, DLinklist &h2) {
    DNode *p1 = h1, *p2 = h2;
    while (p1->next != h1) {
        p1 = p1->next;
    }
    while (p2->next != h2) {
        p2 = p2->next;
    }
    p1->next = h2;
    p2->next = h1;
    return h1;
}

void Del_Min(LinkList &L) {
    LNode *p, *minp, *pre, *minpre;
    
    while (L->next != L) {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d ", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    printf("\n");
    free(L);
}

typedef struct LNode20 {
    ElemType data;
    struct LNode20 *pred, *next;
    int freq;
} LNode20, *LinkList20;

// 非循环双向链表
LNode20 *Locate(LinkList20 &L, ElemType x) {
    LNode20 *p = L->next;
    
    while (p && p->data != x) {
        p = p->next;
    }
    if (!p) {
        return NULL;
    }
    p->freq += 1;
    
    if (p->next != NULL) {
        p->next->pred = p->pred;
    }
    p->pred->next = p->next;
    
    LNode20 *q = p->pred;
    while (q != L && p->freq >= q->freq) {
        q = p->pred;
    }
    
    q->next->pred = p;
    p->next = q->next;
    
    p->pred = q;
    q->next = p;
    
    return p;
}

// 链表倒数第 k 个位置的结点
bool Search_k_D(LinkList &L, int k) {
    LNode *p = L->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    int i = len - k;
    if (i < 0) {
        return false;
    }
    p = L->next;
    while (i > 0) {
        p = p->next;
        i--;
    }
    printf("%d \n", p->data);
    return true;
}

bool Search_k(LinkList &L, int k) {
    LNode *p = L->next, *q = L->next;
    int count = 0;
    while (p) {
        if (count < k) {
            count++;
        } else {
            q = q->next;
        }
        p = p->next;
    }
    if (count < k) {
        return false;
    }
    printf("%d \n", q->data);
    return true;
}

int length(LinkList L) {
    LNode *p = L->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

// 未测试
LNode *find_addr_D(LinkList &L1, LinkList &L2) {
    int len1 = length(L1), len2 = length(L2);
    LNode *p = L1->next, *q = L2->next;
    
    if (len1 < len2) {
        int sum = len1 + len2;
        len2 = len1;
        len1 = sum - len2;
        p = L2->next;
        q = L1->next;
    }
    
    int diff = len1 - len2;
    while (p && q) {
        if (diff > 0) {
            diff--;
            p = p->next;
        } else {
            if (p == q) {
                return p;
            } else {
                p = p->next;
                q = q->next;
            }
        }
    }
    
    return NULL;
}

LNode *find_addr(LinkList &str1, LinkList &str2) {
    LNode *p, *q;
    int m = length(str1);
    int n = length(str2);
    for (p = str1; m > n; m--) {
        p = p->next;
    }
    for (q = str2; m < n; n--) {
        q = q->next;
    }
    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

// 链表中绝对值相等的结点仅保留第一个
void func23(LinkList &L, int n) {
    int *arr = (int *)malloc(sizeof(int) * (n+1));
    LNode *p = L, *q;
    
    for (int i = 0; i < n + 1; i++) {
        arr[i] = 0;
    }
    
    while (p->next) {
        int m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (arr[m] == 0) {
            arr[m] = 1;
            p = p->next;
        } else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    free(arr);
}

// 判断链表是否有环
bool IsLinkCircle(LinkList L) {
    LNode *slow = L, *fast = L;
    while (slow && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow == NULL || fast->next == NULL) {
        return false;
    }
    LNode *p1 = L, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

// a1,a2,...,an 转换成 a1,an,a2,an-1,...
void change_list(LinkList &L) {
    LNode *p, *q, *r, *s;
    p = q = L;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
        while (q->next != NULL) {
            q = q->next;
        }
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q=r;
    }
}

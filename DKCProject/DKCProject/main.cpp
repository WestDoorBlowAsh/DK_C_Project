//
//  main.cpp
//  DKCProject
//
//  Created by 邓凯 on 2020/5/18.
//  Copyright © 2020 dk. All rights reserved.
//

#include <iostream>
#include "bailian/1000_A_B_Problem.c"
#include "leetCode101/02_greedy.hpp"
#include "List/SqList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
//    run();
    SqList L;
    int arr[6] = {4,2,6,3,7};
    InitList(L, arr, 5);
    PrintList(L);
    
    ListInsert(L, 5, 100);
    PrintList(L);
    
//    DestroyList(L);
//    PrintList(L);
    
//    ListInsert(L, 0, 100);
//    PrintList(L);
//    
//    ListInsert(L, 3, 100);
//    PrintList(L);
//    
//    ElemType e;
//    
//    ListDelete(L, 3, e);
//    printf("删除元素 %d\n", e);
//    PrintList(L);
//    
//    ListDelete(L, 0, e);
//    printf("删除元素 %d\n", e);
//    PrintList(L);
//    
//    ListDelete(L, 6, e);
//    printf("删除元素 %d\n", e);
//    PrintList(L);
    
    return 0;
}

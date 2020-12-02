//
//  02_greedy.cpp
//  DKCProject
//
//  Created by 邓凯 on 2020/11/27.
//  Copyright © 2020 dk. All rights reserved.
//

/**
 // 打印 vector
 copy(children.begin(), children.end(), ostream_iterator<int> (cout, " "));
 cout << endl;
 */

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

#pragma mark - 题目解法
/** 455
 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃 最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩 子可以吃饱。
 */
int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (children[child] <= cookies[cookie]) {
            child++;
        }
        cookie++;
    }
    return child;
}

/** 135
 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所 有孩子至少要有一个糖果。求解最少需要多少个糖果。
 */
int candy(vector<int>& ratings) {
    int size = (int)ratings.size();
    if (size < 2) {
        return size;
    }
    vector<int> candys(size, 1);
    for (int i = 1; i < size; i++) {
        if (ratings[i] > ratings[i-1]) {
            candys[i] = candys[i-1] + 1;
        }
    }
    for (int i = size - 1; i > 0; i--) {
        if (ratings[i] < ratings[i-1]) {
            candys[i-1] = max(candys[i-1], candys[i] + 1);
        }
    }
    return std::accumulate(candys.begin(), candys.end(), 0);
}
int candy_01(vector<int>& ratings) {
    int size = (int)ratings.size();
    vector<int> candys = vector<int>(size, 1);
    
//    copy(ratings.begin(), ratings.end(), ostream_iterator<int> (cout, " "));
//    cout << endl;
    
    for (int i = 0, j = i + 1; j < size; i++, j++) {
        if (ratings[i] < ratings[j] && candys[i] >= candys[j]) {
            candys[j] = candys[i] + 1;
        }
//        else if (ratings[i] == ratings[j]) {
//            candys[i] = candys[j] = max(candys[i], candys[j]);
//        }
    }
    
    copy(candys.begin(), candys.end(), ostream_iterator<int> (cout, " "));
    cout << endl ;// << sum << endl;
    
    for (int i = size - 1, j = i - 1; j >= 0; i--, j--) {
        if (ratings[i] < ratings[j] && candys[i] >= candys[j]) {
            candys[j] = candys[i] + 1;
        }
//        else if (ratings[i] == ratings[j]) {
//            candys[i] = candys[j] = max(candys[i], candys[j]);
//        }
    }
     
    copy(candys.begin(), candys.end(), ostream_iterator<int> (cout, " "));
    cout << endl ;// << sum << endl;
    
    int sum = 0;
    for (int i = 0; i < candys.size(); i++) {
        sum += candys[i];
    }
    
    return sum;
}

/** 435
 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
 */
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    return 0;
}

#pragma mark - 测试用例

void findContentChildren_test() {
    vector<int> children = {4,2,3};
    vector<int> cookies = {1,2,3};
    int res = findContentChildren(children, cookies);
    cout << "result = " << res << endl;
}

void candy_test() {
    vector<int> ratings;
    int res;
    ratings = {1,0,2};
    res = candy(ratings);
    cout << "result = " << res << endl;

    ratings = {1,3,3,3,1};
    res = candy(ratings);
    cout << "result = " << res << endl;
    
    ratings = {1,2,87,87,87,2,1};
    res = candy(ratings);
    cout << "result = " << res << endl;
    
}

int createVector(int a) {
    cout << a << endl;
    return 0;
}

int eraseOverlapIntervals_test() {
    createVector(10);
    
//    vector<vector<int>> intervals;
//
//    int arr[][2] = {{1,2},{2,4},{1,3}};
//    int arrLength = sizeof(arr)/sizeof(arr[0]);
//    int eleLength = sizeof(arr[0])/sizeof(arr[0][0]);
//
//    intervals = vector<vector<int>>();
//    for (int i = 0; i < arrLength; i++) {
//        vector<int> temp = vector<int>();
//        for (int j = 0; j < eleLength; j++) {
//            temp.push_back(arr[i][j]);
//        }
//        intervals.push_back(temp);
//    }
//
//    for (int i = 0; i < intervals.size(); i++) {
//        copy(intervals[i].begin(), intervals[i].end(), ostream_iterator<int> (cout, " "));
//        cout << endl ;
//    }
    
    return 0;
}

void run() {
    eraseOverlapIntervals_test();
}

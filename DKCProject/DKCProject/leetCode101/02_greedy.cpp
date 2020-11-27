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
 cout << "\n";
 */

#include <vector>
#include <iostream>

using namespace std;

#pragma mark - 题目解法

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

int candy(vector<int>& ratings) {
    vector<int> candys = vector<int>(ratings.size(), 1);
    
    copy(candys.begin(), candys.end(), ostream_iterator<int> (cout, " "));
    cout << "\n";
    
    for (int i = 0; i < ratings.size(); i++) {
        
    }
    
    return 0;
}


#pragma mark - 测试用例

void findContentChildren_test() {
    vector<int> children = {4,2,3};
    vector<int> cookies = {1,2,3};
    int res = findContentChildren(children, cookies);
    cout << "result = " << res << "\n";
}

void candy_test() {
    vector<int> ratings = {4,2,3};
//    vector<int> cookies = {1,2,3};
    int res = candy(ratings);
    cout << "result = " << res << "\n";
}

void run() {
    candy_test();
}

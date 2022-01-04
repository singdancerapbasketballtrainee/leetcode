//
// Created by heqimin on 2022/1/5.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <iostream>

int min(int x,int y);

int max(int x,int y);

// 链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class solution {
    using string = std::string;
public:
    //快排
    void quick(std::vector<int> &nums,int left,int right); // 指定下标
    void quickSort(std::vector<int>&nums);  // 整个数组
    //反转链表
    ListNode* reverseList(ListNode* head);
    // 最长回文
    string longestPalindrome1(string s); // 方法一：遍历（中心点移动&两边拓展
    // Z 字形变换
    string convert(string s, int numRows);
};

std::ostream &operator<<(std::ostream &out,std::vector<int>&nums);



#endif //CPP_SOLUTION_H

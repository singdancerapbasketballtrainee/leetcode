//
// Created by heqimin on 2022/1/5.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <iostream>

using namespace std;

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
//    using string = std::string;

public:
    //快排
    void quick(std::vector<int> &nums,int left,int right); // 指定下标
    void quickSort(std::vector<int>&nums);  // 整个数组
    // 反转链表
    ListNode* reverseList(ListNode* head);
    // 删除链表的倒数第 N 个结点
    ListNode* removeNthFromEnd(ListNode* head, int n);
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    // 合并K个升序链表
    ListNode* mergeKLists1(vector<ListNode*>& lists);
    ListNode* mergeKLists2(vector<ListNode*>& lists);
    // K 个一组翻转链表
    ListNode* reverseKGroup(ListNode* head, int k);
    // 最长回文
    string longestPalindrome1(string s); // 方法一：遍历（中心点移动&两边拓展
    // Z 字形变换
    string convert(string s, int numRows);
    // 3数求和
    vector<vector<int>> threeSum(vector<int>& nums);
    // 数字转罗马数字
    string int2Roman(int num);
    // 罗马数字转数字
    int romanToInt(string s);
    int romanToInt2(string s);
    // 最长有效括号
    int longestValidParentheses(string s);
    // 有效的括号
    bool isValid(string s);
};

int R2I(char r);
std::ostream &operator<<(std::ostream &out,std::vector<int>&nums);



#endif //CPP_SOLUTION_H

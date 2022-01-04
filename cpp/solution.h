//
// Created by heqimin on 2022/1/5.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <iostream>

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
    void quick(std::vector<int> &nums,int left,int right);
    void quickSort(std::vector<int>&nums);
    static ListNode* reverseList(ListNode* head);
    string longestPalindrome(string s);
};

std::ostream &operator<<(std::ostream &out,std::vector<int>&nums);
#endif //CPP_SOLUTION_H

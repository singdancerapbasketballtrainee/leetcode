//
// Created by heqimin on 2022/1/5.
//

#include "solution.h"

void solution::quickSort(std::vector<int> &nums) {
    auto left = 0;
    auto right = nums.size() - 1;
    quick(nums,left,right);
}

void solution::quick(std::vector<int> &nums, int left, int right) {
    if (nums.size() <= 1 ||left >= right ) return;
    auto key = left ;
    auto l = left;
    auto r = right;
    while(l != r){
        while (nums[r] >= nums[key] && l != r) --r;
        while (nums[l] <= nums[key] && l != r) ++l;
        if(l != r) std::swap(nums[l],nums[r]);
    }
    std::swap(nums[key],nums[l]);
    quick(nums,left,l -1);
    quick(nums, l+1,right);
}

ListNode *solution::reverseList(ListNode *head) {
    ListNode* cur = nullptr;
    auto pre = head;
    while(pre){
        auto tmp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = tmp;
    }
    return cur;
}

solution::string solution::longestPalindrome(solution::string s) {
    auto length = s.size();
    auto max_palindrome_length = 0;
    int radius;
    string longest_palindrome;
    for(int center_pos = 0;center_pos < length;center_pos++){
        auto palindrome_length = 1;
        // 奇数长度回文
        for( radius = 0;radius <= center_pos && radius < length - center_pos;radius++){
            if(s[center_pos - radius] != s[center_pos + radius]){
                break;
            }
            palindrome_length += 2;
        }
        if (palindrome_length >= max_palindrome_length){
            max_palindrome_length = palindrome_length;
            radius --;
            longest_palindrome = s.substr(center_pos - radius,radius * 2 + 1);
        }
        //偶数
        if(s[center_pos] != s[center_pos +1]){
            continue;
        }
        palindrome_length = 2;
        for( radius = 0;radius <= center_pos && radius < length - center_pos - 1;radius++){
            if(s[center_pos - radius] != s[center_pos + 1 + radius]){
                break;
            }
            palindrome_length += 2;
        }
        if (palindrome_length >= max_palindrome_length){
            max_palindrome_length = palindrome_length;
            radius --;
            longest_palindrome = s.substr(center_pos - radius,radius * 2 + 2);
        }
    }
    return longest_palindrome;
}

std::ostream &operator<<(std::ostream &out, std::vector<int> &nums) {
    for(auto a:nums){
        out << a << ", ";
    }
    return out << std::endl;
}
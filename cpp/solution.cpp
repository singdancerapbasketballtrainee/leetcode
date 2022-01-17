//
// Created by heqimin on 2022/1/5.
//

#include "solution.h"
#include <algorithm>
#include <map>
#include <stack>

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

// 反转链表
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

ListNode *solution::removeNthFromEnd(ListNode *head, int n) {
    auto reveres_list = reverseList(head);
    if(n == 1){
        return reverseList(reveres_list->next);
    }
    auto cur = reveres_list;
    for(auto i = 0;i < n - 2;i++){
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return reverseList(reveres_list);
}

ListNode *solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
    if(list1 == nullptr){
        return list2;
    }
    if(list2 == nullptr){
        return list1;
    }
    ListNode* cur;
    if (list1->val <= list2->val){
        cur = list1;
        list1 = list1->next;
    } else{
        cur = list2;
        list2 = list2->next;
    }
    auto ret_list = cur;
    while (list1 != nullptr || list2 != nullptr){
        if(list1 == nullptr){
            cur->next = list2;
            break;
        }
        if(list2 == nullptr){
            cur->next = list1;
            break;
        }
        if (list1->val <= list2->val){
            cur->next = list1;
            list1 = list1->next;
        } else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    return ret_list;
}

ListNode *solution::mergeKLists1(vector<ListNode *> &lists) {
    if(lists.empty()) return nullptr;
    auto list = lists[0];
    int i = 1;
    while (i < lists.size()){
        list = mergeTwoLists(list,lists[i]);
    }
    return list;
}

ListNode *solution::mergeKLists2(vector<ListNode *> &lists){
    if(lists.empty()) return nullptr;
    if(lists.size() == 1) return lists[0];
    if(lists.size() == 2) return mergeTwoLists(lists[0],lists[1]);
    auto mid_pos = lists.size() / 2;
    auto lists1 = vector<ListNode *>(mid_pos);
    auto lists2 = vector<ListNode *>(lists.size()-mid_pos);
    for(auto i = 0;i < mid_pos;i++){
        lists1[i] = lists[i];
    }
    for(auto i = 0;i < lists.size() - mid_pos;i++){
        lists2[i] = lists[mid_pos + i];
    }
    return mergeTwoLists(mergeKLists2(lists1), mergeKLists2(lists2));
}

ListNode* solution::reverseKGroup(ListNode* head, int k){
    auto new_head = new ListNode;
    auto cur = new_head;
    auto cnt = 0;
    auto last_head = head;
    auto next_head = head;
    while (head != nullptr){
        if(cnt++ == k){
            next_head = head->next;
            head->next = nullptr;
            cur->next = reverseList(last_head);
            cur = last_head;
            head = last_head;
            head->next = next_head;
            last_head = next_head;
            cnt = 0;
        }
        head = head->next;
    }
    return  new_head->next;
}

string solution::longestPalindrome1(string s) {
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

string solution::convert(string s, int numRows) {
    if(numRows == 1) return s;
    auto new_str = s;
    auto max_interval = 2 * (numRows - 1);
    auto str_pos = 0;
    for(auto r = 0;r < numRows;r ++){
        auto first_in = 2*(numRows - r-1);
        auto second_int = max_interval - first_in;
//        std::cout << "r: " << r << " interval: " << first_in << " " << second_int << std::endl;
        auto pos = r;
        while (pos < s.length()){
            new_str[str_pos++] = s[pos];
            // 避免溢出 && 第一行和倒数第一行只加一次
            if(pos + first_in < s.length() && first_in * second_int ){
                pos += first_in;
                new_str[str_pos++] = s[pos];
                pos += second_int;
            } else{
                pos += max_interval;
            }
        }
    }
    return new_str;
}

vector<vector<int>> solution::threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    if(nums.size() < 3) return ret;
    auto tmp = nums;
    sort(tmp.begin(),tmp.end());
    for(auto left = tmp.begin();left != tmp.end() - 2;left++){
        if(left != tmp.begin() && *left == *(left - 1)) continue;
        auto right = tmp.end() - 1;
        for(auto mid = left + 1;mid  < right;mid ++){
            if(mid != left + 1 && *mid == *(mid - 1)) continue;
            while (mid  < right && *left + *mid + *right > 0) right--;
            if(mid == right)break;
            if(*left + *mid + *right == 0) ret.push_back(vector<int>{*left,*mid,*right});
        }
    }
    return ret;
}

string solution::int2Roman(int num) {
    int  nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans;
    for(int i = 0;i<13;i++){
        while (num >= nums[i]){
            num -= nums[i];
            ans += romans[i];
        }
    }
    return ans;
}

int solution::romanToInt(string s) {
    map<char,int> r2i = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    if(s.empty()) return 0;
    auto roman = 0;
    for(auto iter = s.begin();iter < s.end() - 1; iter++){
        if(r2i[*iter] < r2i[*(iter + 1)]){
            roman -= r2i[*iter];
        } else{
            roman += r2i[*iter];
        }
    }
    return roman + r2i[*(s.end()-1)];
}

int solution::romanToInt2(string s) {
    if(s.empty()) return 0;
    auto roman = 0;
    for(auto iter = s.begin();iter < s.end() - 1; iter++){
        if(R2I(*iter) < R2I(*(iter + 1))){
            roman -= R2I(*iter);
        } else{
            roman += R2I(*iter);
        }
    }
    return roman + R2I(*(s.end()-1));
}

int solution::longestValidParentheses(string s) {
    // todo
    return 0;
}

bool solution::isValid(string s) {
    if(s.length() % 2 ) return false;
    stack<char> stk;
    map<char,char> pairs = {
            {')','('},
            {']','['},
            {'}','{'}
    };
    for(auto ch:s){
        if(pairs.count(ch)){
            if(stk.empty()||stk.top() != pairs[ch]){
                return false;
            }else{
                stk.pop();
            }
        }else{
            stk.push(ch);
        }
    }
    return stk.empty();
}


inline int R2I(char r){
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

inline std::ostream &operator<<(std::ostream &out, std::vector<int> &nums) {
    for(auto a:nums){
        out << a << ", ";
    }
    return out << std::endl;
}

inline int min(int x,int y){
    return x<y?x:y;
}

inline int max(int x,int y){
    return x>y?x:y;
}
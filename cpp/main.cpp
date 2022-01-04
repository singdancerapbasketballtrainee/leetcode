//
// Created by heqimin on 2022/1/5.
//

#include "solution.h"

int main(){
    auto * sol = new solution;
//    std::vector<int> nums {5,2,4,6,7,1,43423,31,5325,62346453,314513,4645};
//    sol->quickSort(nums);
//    std::cout << nums;
//    auto s = "sbabk";
//    std::cout << sol->longestPalindrome1(s);
    auto s = "PAYPALISHIRING";
    auto numRows = 3;
    std::cout<<sol->convert(s,numRows);
}
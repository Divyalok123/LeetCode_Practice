/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3637/
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0) return 0;
        return __builtin_popcount(num) + 31 - __builtin_clz(num);
    }
};
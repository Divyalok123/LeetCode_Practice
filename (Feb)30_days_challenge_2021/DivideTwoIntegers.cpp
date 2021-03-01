/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool check = (dividend > 0) == (divisor > 0);
        long div = abs(dividend);
        long dis = abs(divisor);
        
        
        long ans = 0;
        for(int i = 31; i >= 0; i--) {
            if((div >> i)-dis >= 0) {
                ans += (1 << i);
                div -= dis << i;
            }
        }
        
        
        return !check ? -ans : ans;
    }
};
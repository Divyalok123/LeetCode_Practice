/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3554/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        
        int d = 1;
        for(; d*d <= n; d++)
            if(n%d == 0 && --k == 0)
                return d;
        d--;
        if(d*d == n) d--;
        
        for(; d >= 1; d--)
            if(n%d == 0 && --k == 0)
                return n/d;
        
        return -1;
    }
};
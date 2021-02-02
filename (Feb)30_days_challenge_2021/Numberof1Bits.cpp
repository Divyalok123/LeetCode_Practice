/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Solution 4
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans++;
            n &= (n-1);
        }
        return ans;
    }
};

// Solution 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans++;
            n -= (n&-n);
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            if(n&(1<<i)) ans++;
        }
        return ans;
    }
};

// Solution 1 one-liner
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
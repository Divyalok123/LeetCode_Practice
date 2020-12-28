/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3583/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int reachNumber(int target) {
        if(target == 0) return 1;
        if(target < 0) target *= -1;
        
        long long n = ceil((sqrt(8ll*target + 1) - 1)/2ll);
        long long newv = n*(n+1)/2ll;
        
        if(newv == target) return n;
        newv -= target;
        return newv&1 ? n + 1 + (n&1) : n;        
    }
};
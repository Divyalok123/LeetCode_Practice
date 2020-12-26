/*
https://leetcode.com/problems/consecutive-numbers-sum/
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* Optimised - AC */
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        int v = (sqrt(1 + 8ll*n)-1)/2;

        for(int i = 2; i <= v; i++) {
            if((n - i*(i+1)/2)%i == 0)
                ans++;
        }
        
        return ans;
    }
};

/* Too SLow (Iterating to check) - TLE */
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int limn = (sqrt(1 + 8ll*n)-1)/2;
        int ans = 0;

        auto val = [](int x){ return x*(x+1)/2;};

        int c = 0;
        while(limn) {
            int v = val(limn) + c*limn;
            if(v == n) ans++, limn--;
            else if(v > n) limn--;
            c++;
        }   
        
        return ans;
    }
};
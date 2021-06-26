/*
https://leetcode.com/problems/domino-and-tromino-tiling/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// below is same as this dp
class Solution {
public:
    #define MOD 1000000007
    int numTilings(int n) {
        if(n == 1) return 1;
        
        int dp[n+1];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) 
            dp[i] = (dp[i-1] * 2ll + dp[i-3]) % MOD;
        
        return dp[n];
  }
};

// up down approach - O(n)
class Solution {
public:
    #define MOD 1000000007
    int numTilings(int n) {
        if(n == 1) return 1;
        
        int dp[n+1], up[n+1], down[n+1];
        dp[0] = dp[1] = 1;
        up[1] = down[1] = 0;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + 0ll + up[i-1] + down[i-1])% MOD;
            up[i] = (down[i-1] + dp[i-2]) % MOD;
            down[i] = (up[i-1] + dp[i-2]) % MOD;
        }
        
        return dp[n];
  }
};
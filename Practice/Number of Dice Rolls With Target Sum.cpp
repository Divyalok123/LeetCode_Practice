/*
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bottom-up dp O(target) space
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int MOD = 1000000007;
        if(target > 900 || d*f < target)
            return 0;
        
        if(target == 900)
            return d == 30 && f == 30;
    
        int dp[target+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= f; i++)
            if(i <= target)
                dp[i] = 1;
        
        for(int i = 2; i <= d; i++) {
            for(int j = target; j >= 1; j--) {
                dp[j] = 0;
                for(int k = 1; k <= f; k++) {
                    if(k <= j) {
                        dp[j] += dp[j-k];
                        dp[j] %= MOD;
                    }
                }
            }
        }
        
        return dp[target];
    }
};

// bottom-up dp O(d*target) space
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int MOD = 1000000007;
        if(target > 900)
            return 0;
        
        if(target == 900)
            return d == 30 && f == 30;
    
        int dp[31][901];
        memset(dp, 0, 27931*sizeof(int));
        dp[0][0] = 1;
        
        for(int i = 1; i <= d; i++) {
            for(int j = 1; j <= target; j++) {
                for(int k = 1; k <= f; k++) {
                    if(k <= j) {
                        dp[i][j] += dp[i-1][j-k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        
        return dp[d][target];
    }
};

// top-down dp
class Solution {
public:
    int MOD; 
    int cache[31][1001];
    int solve(int d, int f, int target) {
        if(d == 0 && target == 0)
            return 1;
        
        if(d == 0 || target == 0 || d > target || d*f < target)
            return 0;
        
        if(cache[d][target] != -1)
            return cache[d][target];
        
        int ans = 0;
        for(int i = 1; i <= f; i++) {
            if(i <= target) {
                int val = solve(d-1, f, target-i);
                ans = (ans+val)%MOD;
            }
        }
        
        return cache[d][target] = ans;
    } 
    
    int numRollsToTarget(int d, int f, int target) {
        MOD = 1000000007;
        if(target > 900)
            return 0;
        
        if(target == 900)
            return d == 30 && f == 30;
        
        memset(cache, -1, 31031*sizeof(int));
        return solve(d, f, target);
    }
};
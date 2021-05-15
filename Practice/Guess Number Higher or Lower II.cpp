/*
https://leetcode.com/problems/guess-number-higher-or-lower-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// DP with Deque - O(n^2)
 

// for the sake of speed O(1)
static int dp[201][201];
static void helper() {
    for(int i = 1; i <= 200; i++)
        dp[i][i] = 0;

    for(int i = 1; i < 200; i++)
        dp[i][i+1] = i;

    for(int i = 200-2; i >= 1; i--) {
        for(int j = i+2; j <= 200; j++) {                
            int val = INT_MAX;
            for(int k = i+1; k < j; k++)
                val = min(val, k + max(dp[i][k-1], dp[k+1][j]));
            dp[i][j] = val;
        }
    }
}

static auto gett = [](){helper(); return 0;}();

class Solution {
public:
    
    int getMoneyAmount(int n) {
        return dp[1][n];
    }
};

// bottom-up dp O(n^3)
class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1) return 0;
        int dp[n+1][n+1];
        
        for(int i = 1; i <= n; i++)
            dp[i][i] = 0;
        
        for(int i = 1; i < n; i++)
            dp[i][i+1] = i;
        
        for(int i = n-2; i >= 1; i--) {
            for(int j = i+2; j <= n; j++) {                
                int val = INT_MAX;
                for(int k = i+1; k < j; k++)
                    val = min(val, k + max(dp[i][k-1], dp[k+1][j]));
                dp[i][j] = val;
            }
        }
        
        return dp[1][n];
    }
};

// top-down dp O(n^3)
class Solution {
public:

    int solve(int l, int r, vector<vector<int>>& cache) {
        if(cache[l][r] != -1)
            return cache[l][r];

        if(r == l+2)
            return cache[l][r] = l+1;
        
        if(r == l+1)
            return cache[l][r] = l;
        
        if(l == r)
            return cache[l][r] = 0;
        
        int ans = INT_MAX;
        for(int i = l+1; i < r; i++) {
            int val = i + max(solve(l, i-1, cache), solve(i+1, r, cache));
            if(val < ans)
                ans = val;
        }
        
        return cache[l][r] = ans;
    } 
    
    int getMoneyAmount(int n) {
        if(n == 1) return 0;
        vector<vector<int>> cache(n+1, vector<int>(n+1, -1));
        return solve(1, n, cache);
    }
};
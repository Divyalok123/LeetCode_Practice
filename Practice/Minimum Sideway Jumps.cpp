/*
https://leetcode.com/problems/minimum-sideway-jumps/
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int n = obs.size()-1;
        array<int, 3> dp;
        dp[1] = 0;
        dp[0] = dp[2] = 1;
        
        for(int i = 1; i < n; i++) {
            array<int, 3> newdp;
            for(int j = 0; j < 3; j++) {
                if(obs[i] == j+1 || obs[i+1] == j+1)
                    newdp[j] = 100000000;
                else {
                    newdp[j] = dp[j];
                    for(int k = 0; k < 3; k++)
                        if(k != j && dp[k] + 1 < newdp[j])
                            newdp[j] = dp[k]+1;
                }
            }
            dp = newdp;
        }
            
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++)
            if(dp[i] < ans)
                ans = dp[i];
        return ans;
    }
};

// bottom-up dp O(N) space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        int dp[n][3];
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;
        
        for(int i = 1; i < n-1; i++) {
            for(int j = 0; j < 3; j++) {
                if(obs[i] == j+1 || obs[i+1] == j+1)
                    dp[i][j] = 100000000;
                else {
                    dp[i][j] = dp[i-1][j];
                    for(int k = 0; k < 3; k++) {
                        if(k != j && dp[i-1][k] + 1 < dp[i][j])
                            dp[i][j] = dp[i-1][k]+1;
                    }
                }
            }
        }
            
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++)
            if(dp[n-2][i] < ans)
                ans = dp[n-2][i];
        return ans;
    }
};

// using top-down dp
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int solve(vector<int>& obs, int i, int lane, vector<vector<int>>& dp) {
        if(i == obs.size()-1)
            return 0;
        
        int& ans = dp[i][lane];
        if(ans != -1)
            return ans;
        
        if(obs[i+1] != lane+1)
            return ans = solve(obs, i+1, lane, dp);
        
        int val = INT_MAX;
        for(int j = 0; j < 3; j++)
            if(lane != j && obs[i] != j+1)
                val = min(val, 1 + solve(obs, i, j, dp));
        
        return ans = val;
    }
    
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(obs, 0, 1, dp);        
    }
};
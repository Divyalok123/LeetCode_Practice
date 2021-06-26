/*
https://leetcode.com/problems/triangle/ 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// improved
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        if(n == 1) return tri[0][0];
        
        vector<int> dp(n+1);
        for(int r = n-1; r >= 0; r--) {
            for(int c = 0; c <= r; c++)
                dp[c] = (dp[c] < dp[c+1] ? dp[c] : dp[c+1]) + tri[r][c];
        } 
        
        return dp[0];
    }
};

// simple bottom-up dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        if(n == 1) return tri[0][0];
        
        vector<int> dp(1, tri[0][0]);
        for(int r = 1; r < n; r++) {
            vector<int> newdp(r+1);
            newdp[0] = dp[0] + tri[r][0];
            for(int c = 1; c < r; c++)
                newdp[c] = min(dp[c-1], dp[c]) + tri[r][c];
            newdp[r] = dp[r-1] + tri[r][r];
            dp = newdp;
        }
        
        int ans = INT_MAX;
        for(int& i: dp)
            if(i < ans)
                ans = i;
        
        return ans;
    }
};
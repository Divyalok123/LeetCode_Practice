/*
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bottom-up dp : dp[i][j] represents count taken form left and from right for i and j respectively
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size(), m = mult.size();
        int diff = n-m;
        
        int dp[m+1][m+1]; // states: no. of elements picked from left and right
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        
        int ans = INT_MIN;
        
        for(int i = 1; i <= m; i++)
            dp[i][0] = dp[i-1][0] + nums[i-1] * mult[i-1];
        ans = max(ans, dp[m][0]);
        
        for(int j = 1; j <= m; j++) 
            dp[0][j] = dp[0][j-1] + nums[n-j] * mult[j-1];
        ans = max(ans, dp[0][m]);
        
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m-i; j++) {
                dp[i][j] = max(dp[i-1][j] + nums[i-1] * mult[i+j-1], dp[i][j-1] + nums[n-j] * mult[i+j-1]); 
                if(i + j == m)
                    ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};

// top-down dp
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<int>> cache;
    int dfs(vector<int>& nums, vector<int>& mult, int l, int r, int ind) {
        if(ind == mult.size()) return 0;
        
        if(cache[l][ind] != -1)
            return cache[l][ind];
        
        int f = nums[l] * mult[ind] + dfs(nums, mult, l+1, r, ind+1);
        int s = nums[r] * mult[ind] + dfs(nums, mult, l, r-1, ind+1);
        
        return cache[l][ind] = max(f, s);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size();
        int m = mult.size();
        cache.resize(m+1, vector<int>(m+1, -1));
        return dfs(nums, mult, 0, n-1, 0);
    }
};
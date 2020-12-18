/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3564/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n == 0 ? 0 : nums[0];
        
        vector<int> newv;
        newv.reserve(n+2);
        
        newv.push_back(1);
        for(int& num: nums)
            if(num) newv.push_back(num);
        newv.push_back(1);
        
        n = newv.size();
        int k;
        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int l = 2; l <= n-1; l++) {
            for(int i = 0; i < n-l; i++) {
                for(int j = i+1; j < i+l; j++) {
                    k = dp[i][j] + newv[j]*newv[i]*newv[i+l] + dp[j][i+l];
                    if(k > dp[i][i+l]) 
                        dp[i][i+l] = k;
                }
            }
        }
        
        return dp[0][n-1];
    }
};

/* Solution 1 */
class Solution {
    vector<vector<int>> dp;
public:
    int helper(vector<int>& nums, int l, int r) {
        if(l > r) 
            return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int j = l+1; j < r; j++) {
            ans = max(ans, helper(nums, l, j) 
                          + nums[j]*nums[l]*nums[r]
                          + helper(nums, j, r));
        }
                          
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n == 0 ? 0 : nums[0];
        
        vector<int> newv;
        newv.reserve(n+2);
        
        newv.push_back(1);
        for(int& num: nums)
            if(num) newv.push_back(num);
        newv.push_back(1);
        n = newv.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return helper(newv, 0, n-1);
    }
};
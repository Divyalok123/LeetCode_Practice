/*
https://leetcode.com/contest/weekly-contest-229/problems/maximum-score-from-performing-multiplication-operations/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int X = -10000000;
    int n, m;
    vector<vector<int>> dp;
    
    int run(int ind, int i, vector<int>& nums, vector<int>& mul) {
        if(ind == m) return 0;
        if(dp[ind][i] != X) return dp[ind][i];
        
        int left = run(ind+1, i+1, nums, mul) + mul[ind]*nums[i];
        int right = run(ind+1, i, nums, mul) + mul[ind]*nums[n-(ind-i)-1];
        
        return dp[ind][i] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size(), m = multipliers.size();
        dp.resize(m+1, vector<int>(m+1, X));
        return run(0, 0, nums, multipliers);
    }
};
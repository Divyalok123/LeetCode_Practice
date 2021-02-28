/*
https://leetcode.com/problems/last-stone-weight-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 (DP)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int& i: stones) sum += i;
        vector<vector<bool>> dp(sum/2+1, vector<bool>(n+1));
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        int mm = 0;
        for(int i = 1; i <= n; i++) {
            for(int s = 1; s <= sum/2; s++) {
                if(dp[s][i-1])
                    dp[s][i] = 1;
                else if(s >= stones[i-1])
                    dp[s][i] = dp[s-stones[i-1]][i-1];
                if(dp[s][i] && s > mm) mm = s;
            }
        }
        return sum - 2*mm;
    }
};

// Solution 1 (memo)
class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& stones, int total, int curr, int i) {
        if(i == stones.size()) {
            int ans = total-curr;
            return ans < 0 ? -ans : ans;
        }
        
        if(dp[i][curr] != -1)
            return dp[i][curr];
        
        int a = helper(stones, total-stones[i], curr + stones[i], i+1);
        int b = helper(stones, total, curr, i+1);
        return dp[i][curr] = (a < b) ? a : b;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int& i: stones)
            sum += i;

        dp.assign(n, vector<int>(sum+1, -1));
        return helper(stones, sum, 0, 0);
    }
};
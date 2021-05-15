/*
https://leetcode.com/problems/wiggle-subsequence/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(1) space solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1) return 1;
        if(n == 2) return 2 - (nums[0] == nums[1]);
        
        int cnt1 = 1, cnt2 = 1;
        int scnt1 = 1, scnt2 = 1;
        for(int i = 1; i < n; i++) {
            int diff = nums[i]-nums[i-1];
            if(diff == 0) {
                cnt1 = scnt1;
                cnt2 = scnt2;
            } else if(diff < 0) {
                cnt1 = max(cnt1, scnt2 + 1);
                scnt1 = cnt1;
            } else {
                cnt2 = max(cnt2, scnt1 + 1);
                scnt2 = cnt2;
            }
        }
        
        return max(cnt1, cnt2);
    }
};

// bottom-up dp O(N) Time, O(N) Space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1) return 1;
        if(n == 2) return 2 - (nums[0] == nums[1]);
        
        vector<vector<int>> dp(n, vector<int>(2,1));
        
        for(int i = 1; i < n; i++) {
            int diff = nums[i]-nums[i-1];
            if(diff == 0) {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            } else if(diff < 0) {
                dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
                dp[i][1] = dp[i-1][1];
            } else {
                dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
                dp[i][0] = dp[i-1][0];
            }
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

// bottom-up dp O(N^2) Time, O(N) Space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1) return 1;
        if(n == 2) return 2 - (nums[0] == nums[1]);
        
        vector<vector<int>> dp(n, vector<int>(2,1));
        
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                int diff = nums[i]-nums[j];
                if(diff == 0) 
                    continue;
                else if(diff < 0)
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                else 
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            
            if(ans < dp[i][0]) ans = dp[i][0];
            if(ans < dp[i][1]) ans = dp[i][1];
        }
        
        return ans;
    }
};
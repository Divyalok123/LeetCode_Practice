#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> dp;    
    int helper(vector<int>& nums, int ind, int val) {
        if(ind == nums.size()/2+1)
            return 0;
        
        if(dp[val])
            return dp[val];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            for(int j = i+1; j < nums.size(); j++) {
                int nval = (1 << i) + (1 << j);
                
                if((val&nval) == 0) {
                    ans = max(ans, ind*__gcd(nums[i], nums[j]) + helper(nums, ind+1, val + nval));
                }
            }
        }
        
        return dp[val] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        dp.resize(20000);
        return helper(nums, 1, 0);
    }
};
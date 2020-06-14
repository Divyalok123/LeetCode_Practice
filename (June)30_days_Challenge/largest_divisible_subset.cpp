// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
// Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0 || size == 1) return nums;
        
        sort(nums.begin(), nums.end());
        vector<int> dp(size, 1);
        
        int maxEl = -100;
        for(int i = 1; i < size; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[i]%nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(dp[i] > maxEl) maxEl = dp[i];
        }
        
        vector<int> output;
        int pivot = -1;
        for(int i = size-1; i >= 0; i--)
        {
            if(dp[i] == maxEl && (pivot == -1 || pivot%nums[i] == 0)) 
            {
                if(pivot == -1) pivot = nums[i];
                output.push_back(nums[i]);
                maxEl--;
            }
        }
        return output;
    }
};  
/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// binary search on array - O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
     
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        
        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];
        
        int ans = n+1, i;
        for(i = n-1; i >= 0 && nums[i] > target; i--) {
            int dist = upper_bound(nums.begin(), nums.begin() + i+1, nums[i]-target) - nums.begin();
            ans = min(ans, i-dist+1);
        }
        
        if(i >= 0 && nums[i] == target)
            ans = min(ans, i+1);
        
        return ans == n+1 ? 0 : ans;
    }
};

// binary serach on length - O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    bool ispossible(int len, int target, vector<int>& nums) {
        int val = nums[len-1], n = nums.size();
        if(val >= target)
            return 1;
        
        for(int i = len; i < n; i++)
            if(nums[i]-nums[i-len] >= target)
                return 1;
        
        return 0;
    }
     
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        
        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];
        
        int ans = n+1;
        while(l <= r) {
            int m = l + (r-l)/2;
            
            if(ispossible(m, target, nums)) {
                ans = m;
                r = m-1;
            } else 
                l = m+1;
        }
        
        return ans == n+1 ? 0 : ans;
    }
};
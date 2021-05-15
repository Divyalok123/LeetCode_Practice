/*
https://leetcode.com/problems/make-sum-divisible-by-p/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> um; 

        int sum = 0;
        for(int& i: nums)
            sum = (sum + i)%p;
        
        if(sum == 0) return 0;        
        
        int ans = n, val = 0;
        for(int i = 0; i < n; i++) {            
            val = (val + nums[i])%p;
            um[val] = i+1;
            
            int check = (val-sum+p)%p;
            if(um[check] || check == 0)
                ans = min(ans, i-um[check]+1);
        }
        
        return ans == n ? -1 : ans;
    }
};
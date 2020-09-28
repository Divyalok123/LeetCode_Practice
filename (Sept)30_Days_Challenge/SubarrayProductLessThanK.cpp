/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3475/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mult = 1, ans = 0;
        int fast = 0, slow = 0;
        while(fast < nums.size())
        {
            mult *= nums[fast];
            while(slow <= fast && mult >= k)
                mult /= nums[slow++];
            
            ans += (fast-slow+1);   
            fast++;
        }
        
        return ans;
    }
};
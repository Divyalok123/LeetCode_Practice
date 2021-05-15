/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getlowerbound(vector<int>& nums, int val) {
        int l = 0, r = nums.size();
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] >= val)
                r = m;
            else 
                l = m+1;
        }
        
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int prevind = getlowerbound(nums, target);
        if(prevind == nums.size() || nums[prevind] != target)
            return {-1, -1};
        return {prevind, getlowerbound(nums, target+1)-1};
    }
};
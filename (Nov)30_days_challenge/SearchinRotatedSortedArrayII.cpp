/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3537/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return nums[0] == target;
        int m, i = 0, j = nums.size()-1;
        while(i <= j) {
            m = i + (j-i)/2;
            if(nums[m] == target) return true;
            
            if(nums[i] == nums[m]) {
                i++;
            } else if(nums[i] < nums[m]) {
                if(nums[m] > target && target >= nums[i])
                    j = m-1;
                else
                    i = m+1;
            } else {
                if(nums[m] < target && target <= nums[j])
                    i = m+1;
                else
                    j = m-1;
            }
        }
        return false;
    }
};
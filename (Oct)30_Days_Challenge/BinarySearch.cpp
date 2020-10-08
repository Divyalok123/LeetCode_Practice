/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return (nums[0] == target) ? 0 : -1;
        
        int i = 0, m, j = nums.size()-1;
        while(i <= j) {
            m = (i+j)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                i = m+1;
            else
                j = m-1;
        }
        return -1;
    }
};
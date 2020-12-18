/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3567/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k = n-1, i = 0, j = n-1;
        while(i <= j) {
            if(abs(nums[i]) > abs(nums[j]))
                ans[k--] = nums[i]*nums[i++];
            else
                ans[k--] = nums[j]*nums[j--];
        }
        return ans;
    }
};
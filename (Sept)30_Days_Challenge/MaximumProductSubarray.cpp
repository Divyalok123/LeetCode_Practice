/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3456/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int maxval = nums[0];
        int minval = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minval, maxval);

            maxval = max(maxval * nums[i], nums[i]);
            minval = min(minval * nums[i], nums[i]);

            ans = max(maxval, ans);
        }

        return ans;
    }
};
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN, max_till = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            max_till += nums[i];

            if (max_till > max_sum)
            {
                max_sum = max_till;
            }

            if (max_till < 0)
            {
                max_till = 0;
            }
        }
        return max_sum;
    }
};
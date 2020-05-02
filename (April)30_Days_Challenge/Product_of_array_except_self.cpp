// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> output(nums.size(), 1);
        int temp1 = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            output[i] = temp1;
            temp1 *= nums[i];
        }

        int temp2 = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            output[i] *= temp2;
            temp2 *= nums[i];
        }

        return output;
    }
};
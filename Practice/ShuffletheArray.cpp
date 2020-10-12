/*
https://leetcode.com/problems/shuffle-the-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        if (n == 0)
            return {};

        for (int i = 0; i < n; i++)
        {
            nums[i + n] <<= 10;
            nums[i + n] |= nums[i];
        }

        int l = 0;
        for (int i = n; i < nums.size(); i++)
        {
            nums[l] = nums[i] & 1023;
            nums[l + 1] = nums[i] >> 10;
            l += 2;
        }

        return nums;
    }
};
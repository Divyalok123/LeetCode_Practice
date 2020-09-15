/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3459/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++)
        {
            c = max(i < 1 ? 0 : b, nums[i] + (i < 2 ? 0 : a));
            a = b;
            b = c;
        }
        return max(a, b);
    }
};
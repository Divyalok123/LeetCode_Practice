/*
https://leetcode.com/problems/trapping-rain-water/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int sum = 0;
        int highest = 0, maxval = INT_MIN;

        for (int i = 0; i < n; i++)
            if (height[i] > maxval)
            {
                maxval = height[i];
                highest = i;
            }

        int leftmax = 0;
        for (int i = 1; i < highest; i++)
        {
            if (height[i] > height[leftmax])
                leftmax = i;
            else
                sum += (height[leftmax] - height[i]);
        }

        int rightmax = n - 1;
        for (int i = n - 2; i > highest; i--)
        {
            if (height[i] > height[rightmax])
                rightmax = i;
            else
                sum += (height[rightmax] - height[i]);
        }

        return sum;
    }
};
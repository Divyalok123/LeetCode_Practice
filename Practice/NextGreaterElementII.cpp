/*
https://leetcode.com/problems/next-greater-element-ii/
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/* optimised */
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size(), mi = 0, temp, i;
        if (n == 0)
            return {};
        if (n == 1)
            return {-1};

        stack<int> s;
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[mi])
                mi = i;

        for (i = mi; i >= 0; i--)
            s.push(nums[i]);

        for (i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && (s.top() <= nums[i]))
                s.pop();
            temp = nums[i];
            nums[i] = s.empty() ? -1 : s.top();
            s.push(temp);
        }
        return nums;
    }
};

/* Solution 1 */
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {-1};
        stack<int> s;
        int temp, i;
        for (i = nums.size() - 1; i >= 0; i--)
            s.push(nums[i]);
        for (i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && (s.top() <= nums[i]))
                s.pop();
            temp = nums[i];
            nums[i] = s.empty() ? -1 : s.top();
            s.push(temp);
        }
        return nums;
    }
};
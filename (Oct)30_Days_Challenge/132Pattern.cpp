/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3505/
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define ff first
#define ss second

/* Solution 3 (improvised solution 2)*/
#define ff first
#define ss second
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return false;

        stack<int> s;
        int temp = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < temp)
                return true;
            while (!s.empty() && (nums[i] > s.top()))
            {
                temp = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }
        return false;
    }
};

/* Solution 2 */
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return false;

        stack<pair<int, int>> st;
        int minv = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && (st.top().ff < nums[i]))
                st.pop();
            if (!st.empty() && (st.top().ff > nums[i] && st.top().ss < nums[i]))
                return true;
            minv = min(minv, nums[i]);
            if (minv == nums[i])
                continue;
            else
                st.push({nums[i], minv});
        }
        return false;
    }
};

/* Solution 1 O(n^2) */
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return false;

        int a = INT_MAX, b, j;
        for (int i = 0; i < n - 2; i++)
        {
            a = min(a, nums[i]);
            if (a == nums[i])
                continue;

            for (j = i + 1; j < n; j++)
            {
                if ((nums[j] < nums[i]) && (nums[j] > a))
                    return true;
                // b = max(b, nums[j]);
            }
        }
        return false;
    }
};
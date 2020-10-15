/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3496/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* solution 3 space: O(1) */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 1 || k == 0)
            return;
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;

        int s, e, prev, temp, i = 0, count = 0;
        while (count < n)
        {
            s = i;
            prev = nums[i];
            do
            {
                e = (s + k) % n;
                temp = nums[e];
                nums[e] = prev;
                prev = temp;
                s = e;
                count++;
            } while (s != i);
            i++;
        }
    }
};

/* Solution 2 space: O(1) */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 1 || k == 0)
            return;
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/* Solution 1 space: O(k)*/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 1 || k == 0)
            return;

        int n = nums.size();
        k %= n;

        if (k == 0)
            return;

        vector<int> v(k);
        for (int i = n - k, j = 0; i < n && j < k; i++, j++)
            v[j] = nums[i];

        for (int i = n - k - 1, j = n - 1; i >= 0; i--, j--)
            nums[j] = nums[i];

        for (int i = 0; i < k; i++)
            nums[i] = v[i];
    }
};
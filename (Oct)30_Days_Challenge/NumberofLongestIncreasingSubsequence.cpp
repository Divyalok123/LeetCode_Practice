/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3513/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* O(nlogn) Solution */
//

/* O(n^2) Solution */
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;

        int dp[n], mlen[n];
        for (int i = 0; i < n; i++)
            dp[i] = mlen[i] = 1;

        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] == dp[i] - 1)
                        mlen[i] += mlen[j];
                    else if (dp[j] >= dp[i]) {
                        mlen[i] = mlen[j];
                        dp[i] = dp[j]+1;
                    }
                    // dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == ans)
                count += mlen[i];

        return count;
    }
};

/* O(2^n) */
class Solution
{
public:
    int finalans = 0;
    int flcount = 0;
    int n;
    // vector<int> dp;

    void helper(vector<int> &nums, int i, int currlencount, int prev, bool c)
    {
        if (i == n)
        {
            if (prev == -1)
                return;

            if ((flcount != 0) && (flcount == currlencount) && (c))
                finalans++;
            else if (flcount < currlencount)
            {
                finalans = 1;
                flcount = currlencount;
            }

            return;
        }

        if (prev == -1 || (nums[i] > nums[prev]))
            helper(nums, i + 1, currlencount + 1, i, true);
        helper(nums, i + 1, currlencount, prev, c);
    }

    int findNumberOfLIS(vector<int> &nums)
    {
        n = nums.size();
        if (n <= 1)
            return n;
        // dp.assign(n+1, -1);
        helper(nums, 0, 0, -1, false);
        return finalans;
    }
};
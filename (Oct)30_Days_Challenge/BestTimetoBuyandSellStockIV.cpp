/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3499/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/* Solution 3 */


/* Solution 2 */
class Solution
{
public:
    vector<vector<vector<int>>> dp;
    int helper(int k, int i, vector<int> &prices, bool bought)
    {
        if (i == prices.size() || k == 0)
        {
            return 0;
        }

        if (dp[k][i][bought] != -1)
            return dp[k][i][bought];

        int &ans = dp[k][i][bought];
        if (bought)
        {
            ans = max(helper(k, i + 1, prices, true),
                      prices[i] + helper(k - 1, i + 1, prices, false));
        }
        else
        {
            ans = max(helper(k, i + 1, prices, false),
                      -prices[i] + helper(k, i + 1, prices, true));
        }

        return ans;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        if (k >= prices.size() / 2)
        {
            int ans = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            return ans;
        }

        dp.assign(k + 1, vector<vector<int>>(prices.size() + 1, vector<int>(2, -1)));
        int ans = helper(k, 0, prices, 0);
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;

        int n = prices.size();
        if (k >= n / 2)
        {
            int ans = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            }
            return ans;
        }

        vector<int> dp(k + 1, 0), minv(k + 1, INT_MIN);
        for (auto &a : prices)
        {
            for (int j = 1; j <= k; j++)
            {
                minv[j] = max(minv[j], dp[j - 1] - a);
                dp[j] = max(dp[j], minv[j] + a);
            }
        }

        return dp[k];
    }
};

/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3426/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int dp[3];
        int minv[3];
        fill(minv, minv + 3, prices[0]);
        memset(dp, 0, sizeof(dp)); //memset doesn't always work properly
        for (int i = 1; i < prices.size(); i++)
        {
            for (int k = 1; k <= 2; k++)
            {
                minv[k] = min(minv[k], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - minv[k]);
            }
        }

        return dp[2];
    }
};
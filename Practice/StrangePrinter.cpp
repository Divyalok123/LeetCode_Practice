/*
https://leetcode.com/problems/strange-printer/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    int n;
    string ss;
    vector<vector<int>> dp;

    int helper(int i, int j)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (ss[i] == ss[i + 1])
            return dp[i][j] = helper(i + 1, j);

        if ((ss[i] == ss[j]) || (ss[j] == ss[j - 1]))
            return dp[i][j] = helper(i, j - 1);

        dp[i][j] = 1 + helper(i + 1, j);
        for (int l = i + 1; l <= j; l++)
        {
            if (ss[l] == ss[i])
                dp[i][j] = min(dp[i][j], helper(i + 1, l) + helper(l + 1, j));
        }
        return dp[i][j];
    }

    int strangePrinter(string s)
    {
        if (s.size() <= 1)
            return s.size();
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 2;
        }
        dp[n - 1][n - 1] = 1;

        ss = move(s);
        return helper(0, n - 1);
    }
};

/* Solution 1 */
class Solution
{
public:
    int strangePrinter(string s)
    {
        if (s.size() <= 1)
            return s.size();
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            if (i < n - 1)
                dp[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 2;
        }

        for (int l = 2; l < n; l++)
            for (int i = 0; i + l < n; i++)
            {
                dp[i][i + l] = l + 1;
                for (int k = 0; k < l; k++)
                    dp[i][i + l] = min(dp[i][i + l], dp[i][i + k] + dp[i + k + 1][i + l]);

                if (s[i] == s[i + l])
                    dp[i][i + l]--;
            }

        return dp[0][n - 1];
    }
};
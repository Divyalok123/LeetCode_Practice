/*
https://leetcode.com/problems/decode-ways/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* SOlution 2 */
class Solution
{
public:
    vector<int> dp;
    int numDecodings(string &s)
    {
        if (s[0] == '0')
            return 0;

        int n = s.size();
        if (n == 1)
            return s[0] != '0';
        dp.assign(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '0')
            {
                if (s[i - 2] == '1' || s[i - 2] == '2')
                    dp[i] = dp[i - 2];
                else
                    return 0;
            }
            else
            {
                if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                    dp[i] = dp[i - 1] + dp[i - 2];
                else
                    dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
};

/* Solution 1 */
class Solution
{
public:
    vector<int> dp;
    int helper(string &s, int i)
    {
        if (i == s.size() || i == s.size() - 1)
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
        {
            if (s[i + 1] == '0')
            {
                return dp[i] = helper(s, i + 2);
            }
            else
            {
                return dp[i] = helper(s, i + 1) + helper(s, i + 2);
            }
        }
        else
        {
            return dp[i] = helper(s, i + 1);
        }
    }

    int numDecodings(string &s)
    {
        if (s[0] == '0')
            return 0;

        int n = s.size();
        if (n == 1)
            return s[0] != '0';
        dp.assign(n, -1);
        return helper(s, 0);
    }
};
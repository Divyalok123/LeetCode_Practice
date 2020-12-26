/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3581/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int helper(string &s, int i)
    {
        if (i == s.size() - 1)
            return s[i] != '0';
        if (i >= s.size())
            return 1;
        if (i < s.size() - 1 && s[i] > '2' && s[i + 1] == '0')
            return -1;
        int &ans = dp[i];
        if (ans != -2)
            return ans;

        if (s[i] == '0')
            return ans = -1;
        if (s[i] == '1')
        {
            if (s[i + 1] == '0')
                return ans = helper(s, i + 2);
            else
            {
                int val1 = helper(s, i + 2);
                int val2 = helper(s, i + 1);
                if (val1 == val2 && val2 == -1)
                    return ans = -1;
                return ans = (val1 == -1 ? 0 : val1) + (val2 == -1 ? 0 : val2);
            }
        }
        if (s[i] == '2')
        {
            if (s[i + 1] == '0')
                return helper(s, i + 2);
            else if (s[i + 1] <= '6')
            {
                int val1 = helper(s, i + 2);
                int val2 = helper(s, i + 1);
                if (val1 == val2 && val2 == -1)
                    return ans = -1;
                return ans = (val1 == -1 ? 0 : val1) + (val2 == -1 ? 0 : val2);
            }
            else
            {
                return ans = helper(s, i + 1);
            }
        }

        return ans = helper(s, i + 1);
    }
    int numDecodings(string s)
    {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        dp.assign(s.size() + 1, -2);
        int ans = helper(s, 0);
        return ans == -1 ? 0 : ans;
    }
};
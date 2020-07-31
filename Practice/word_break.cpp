/* https://leetcode.com/problems/word-break/ */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        if (n == 0)
            return true;
        unordered_map<string, bool> _m;
        for (auto word : wordDict)
        {
            _m[word] = true;
        }

        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string w = s.substr(j, i - j);
                if (_m[w] && dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
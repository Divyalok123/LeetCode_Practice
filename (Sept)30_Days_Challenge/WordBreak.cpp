/*
https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/558/week-5-september-29th-september-30th/3477/
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    unordered_set<int> uset;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.size() == 0)
            return true;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            if (uset.find(top) == uset.end())
            {
                uset.insert(top);
                for (auto &a : wordDict)
                {
                    if (a.size() + top <= s.size() && s.substr(top, a.size()) == a)
                    {
                        if (a.size() + top == s.size())
                            return true;
                        q.push(a.size() + top);
                    }
                }
            }
        }
        return false;
    }
};

/* Solution 1 */
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.size() == 0)
            return true;
        unordered_set<string> uset;
        for (auto &a : wordDict)
            uset.insert(a);
        vector<bool> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && (uset.find(s.substr(j, i - j)) != uset.end()))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
/*
https://leetcode.com/problems/regular-expression-matching/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//saving space
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = s.size(), pi = p.size();
        vector<bool> dp(pi+1);
        dp[0] = 1;
        
        for(int i = 2; i <= pi; i++)
            dp[i] = p[i-1] == '*' && dp[i-2];
        
        for(int i = 1; i <= si; i++) {
            bool preval = dp[0];
            dp[0] = 0;
            for(int j = 1; j <= pi; j++) {
                bool anotherpreval = dp[j];
                if(p[j-1] == '*') {
                    dp[j] = dp[j-2] || dp[j] && (p[j-2] == '.' || s[i-1] == p[j-2]);
                } else {
                    dp[j] = (p[j-1] == '.' || s[i-1] == p[j-1]) && preval;
                }
                preval = anotherpreval;
            }
        }
        
        return dp[pi];
    }
};


// bottom-up
class Solution {
public:
    bool isMatch(string s, string p) {
        int si = s.size(), pi = p.size();
        vector<vector<bool>> dp(si+1, vector<bool>(pi+1));
        dp[0][0] = 1;
        
        for(int i = 2; i <= pi; i++)
            dp[0][i] = p[i-1] == '*' && dp[0][i-2];
        
        for(int i = 1; i <= si; i++) {
            for(int j = 1; j <= pi; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]);
                } else {
                    dp[i][j] = (p[j-1] == '.' || s[i-1] == p[j-1]) && dp[i-1][j-1];
                }
            }
        }
        
        return dp[si][pi];
    }
};

// memoization
class Solution
{
public:
    vector<vector<int>> cache;
    bool helper(const string &s, const string &p, int si, int pi, char prev)
    {
        if (si == s.size() && pi == p.size())
            return 1;
        if (pi == p.size())
            return 0;

        if (si == s.size()) //inprove the speed
        {
            if (p.size() - pi >= 2)
            {
                if (p[pi] == '*')
                    pi++;
                for (int i = pi + 1; i < p.size(); i += 2)
                    if (p[i] != '*')
                        return 0;
                if ((p.size() - pi) & 1)
                    return p.back() == '*';
                return 1;
            }
            else
                return p.back() == '*';
        }

        if (cache[si][pi] != -1)
            return cache[si][pi];

        int ans = 0;
        if (pi < p.size() - 1 && p[pi + 1] == '*')
        {
            ans |= helper(s, p, si, pi + 2, p[pi]);
        }

        if (p[pi] == '*')
        {
            if (prev == '.' || s[si] == prev)
                ans |= helper(s, p, si + 1, pi, prev);
            ans |= helper(s, p, si, pi + 1, prev);
        }

        else if (p[pi] == '.' || s[si] == p[pi])
        {
            ans |= helper(s, p, si + 1, pi + 1, p[pi]);
        }

        return cache[si][pi] = ans;
    }

    bool isMatch(string s, string p)
    {
        int si = s.size(), pi = p.size();
        cache.resize(si, vector<int>(pi, -1));
        return helper(s, p, 0, 0, '.');
    }
};

//naive recursion
class Solution
{
public:
    bool helper(const string &s, const string &p, int si, int pi, char prev)
    {
        if (si == s.size() && pi == p.size())
            return 1;
        if (pi == p.size())
            return 0;
        if (si == s.size())
        {
            if (p.size() - pi >= 2)
            {
                if (p[pi] == '*')
                    pi++;
                for (int i = pi + 1; i < p.size(); i += 2)
                    if (p[i] != '*')
                        return 0;
                if ((p.size() - pi) & 1)
                    return p.back() == '*';
                return 1;
            }
            else
                return p.back() == '*';
        }

        int ans = 0;
        if (p[pi] != '*' && pi < p.size() - 1 && p[pi + 1] == '*')
        {
            ans |= helper(s, p, si, pi + 2, p[pi]);
        }

        if (p[pi] == '*')
        {
            if (prev == '.' || s[si] == prev)
                ans |= helper(s, p, si + 1, pi, prev);
            ans |= helper(s, p, si, pi + 1, prev);
        }

        else if (p[pi] == '.' || s[si] == p[pi])
        {
            ans |= helper(s, p, si + 1, pi + 1, p[pi]);
        }

        return ans;
    }

    bool isMatch(string s, string p)
    {
        return helper(s, p, 0, 0, '.');
    }
};

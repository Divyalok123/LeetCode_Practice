/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//solution 3
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        vector<int> lps(n);
        int len = 0, i = 1;
        lps[0] = 0;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len == 0)
                    lps[i++] = 0;
                else
                    len = lps[len - 1];
            }
        }

        return (n % (n - lps.back()) == 0 && lps.back() > 0 && (s.substr(lps.back()) == s.substr(0, n - lps.back())));
    }
};

//solution 2: a really nice solution
class Solution
{
public:
    bool repeatedSubstringPattern(string &s)
    {
        int n = s.size();
        if (n <= 1)
            return false;
        if (n == 2)
            return s[0] == s[1];

        string news = s + s;
        news = news.substr(1, 2 * n - 2);
        cout << news << endl;
        return news.find(s) != -1;
    }
};

//solution 1
class Solution
{
public:
    bool check(string &s, int n1, string &ss, int n2)
    {
        for (int i = 0; i < n1; i++)
        {
            if (s[i] != s[i % n2])
                return false;
        }
        return true;
    }

    bool repeatedSubstringPattern(string &s)
    {
        int n = s.size();
        if (n <= 1)
            return false;
        if (n == 2)
            return s[0] == s[1];

        string ss = "";
        for (int i = 0; i < n / 2; i++)
        {
            ss += s[i];
            if (n % (i + 1) == 0 && check(s, n, ss, i + 1))
                return true;
        }
        return false;
    }
};
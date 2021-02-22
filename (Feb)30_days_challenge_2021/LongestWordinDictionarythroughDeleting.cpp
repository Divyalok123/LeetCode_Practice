/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(string &a, string &b)
    {
        int n = a.size(), m = b.size();
        if (n <= m)
            return n == m ? a == b : 0;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] == b[j])
                i++, j++;
            else
                i++;
        }

        return j == m;
    }

    string findLongestWord(string s, vector<string> &d)
    {

        sort(d.begin(), d.end(), [](string const &a, string const &b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });

        string ans;
        for (auto &i : d)
        {
            if (check(s, i))
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};
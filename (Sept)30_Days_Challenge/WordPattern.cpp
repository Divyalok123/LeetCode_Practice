/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3451/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        int n = pattern.size();
        int x = str.size();
        unordered_map<char, int> p;
        unordered_map<string, int> s;
        vector<string> v;
        int i, j, c = 1;
        for (auto a : pattern)
        {
            if (p.find(a) != p.end())
                continue;
            p[a] = c++;
        }

        c = 1;
        string ss;
        i = 0;
        while (i < x)
        {
            ss = "";
            while (i < x && str[i] != ' ')
                ss += str[i++];
            v.push_back(ss);
            i++;
        }

        if (v.size() != n)
        {
            // cout << "here 1" << endl;
            return false;
        }

        for (auto a : v)
        {
            if (s.find(a) != s.end())
                continue;
            s[a] = c++;
        }

        for (int i = 0; i < n; i++)
            if (p[pattern[i]] != s[v[i]])
            {
                // cout << "here 2" << endl;
                return false;
            }

        return true;
    }
};
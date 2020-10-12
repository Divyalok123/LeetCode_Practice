/*
https://leetcode.com/problems/rearrange-spaces-between-words/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string reorderSpaces(string text)
    {
        if (text.size() == 1)
            return text;

        string ans = "";
        vector<string> v;
        int spaces = 0, i = 0;
        string s;
        while (i < text.size())
        {
            s = "";
            while (i < text.size() && text[i] == ' ')
                spaces++, i++;

            while (i < text.size() && text[i] != ' ')
                s.push_back(text[i++]);
            if (s != "")
                v.push_back(s);
        }

        if (v.size() == 1)
        {
            ans += v[0];
            for (i = 0; i < spaces; i++)
                ans += " ";
            return ans;
        }

        int diff1 = spaces / (v.size() - 1);
        int diff2 = spaces % (v.size() - 1);

        ans += v[0];
        for (i = 1; i < v.size(); i++)
        {
            for (int l = 0; l < diff1; l++)
                ans += " ";
            ans += v[i];
        }

        for (i = 0; i < diff2; i++)
            ans += " ";
        return ans;
    }
};
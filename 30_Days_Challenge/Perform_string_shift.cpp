// You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

// direction can be 0 (for left shift) or 1 (for right shift).
// amount is the amount by which string s is to be shifted.
// A left shift by 1 means remove the first character of s and append it to the end.
// Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
// Return the final string after all operations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    string rightshifter(string s, int n)
    {
        int len = s.length();
        if (n > len)
        {
            n = n % s.length();
        }

        string s1 = "";
        string s2 = "";

        int i;
        for (i = 0; i < len - n; i++)
        {
            s1 += s[i];
        }

        for (int j = i; j < len; j++)
        {
            s2 += s[j];
        }

        string ans = s2 + s1;
        return ans;
    }

    string leftshifter(string s, int n)
    {
        int len = s.length();
        if (n > len)
        {
            n = n % s.length();
        }

        string s1 = "";
        string s2 = "";

        int i;
        for (i = 0; i < n; i++)
        {
            s1 += s[i];
        }

        for (int j = i; j < len; j++)
        {
            s2 += s[j];
        }

        string ans = s2 + s1;
        return ans;
    }

public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int finaldir;
        int finaltimes;

        int timesleft = 0;
        int timesright = 0;
        for (int i = 0; i < shift.size(); i++)
        {
            if (shift[i][0] == 1)
            {
                timesright += shift[i][1];
            }
            else
            {
                timesleft += shift[i][1];
            }
        }

        if (timesleft > timesright)
        {
            finaldir = 0;
            finaltimes = timesleft - timesright;
        }
        else if (timesleft < timesright)
        {
            finaldir = 1;
            finaltimes = timesright - timesleft;
        }
        else
            return s;

        string ans = "";
        if (finaldir == 0)
        {
            ans += leftshifter(s, finaltimes);
        }
        else
            ans += rightshifter(s, finaltimes);

        return ans;
    }
};
/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3454/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int comparestrings(string &a, string &b)
    {
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        if (n == 0)
            while (j < m)
            {
                if (b[j] != '0')
                    return -1;
                else
                    j++;
            }

        if (m == 0)
            while (i < n)
            {
                if (a[i] != '0')
                    return 1;
                else
                    i++;
            }

        if (n != m)
            return n < m ? -1 : 1;

        while (i < n && j < m)
        {
            if (a[i] > b[j])
                return 1;
            else if (a[i] < b[j])
                return -1;
            else
                i++, j++;
        }

        if (i < n)
            return 1;
        else if (j < m)
            return -1;
        return 0;
    }

    int compareVersion(string v1, string v2)
    {

        string s1, s2;
        int i = 0, j = 0, val;
        int n = v1.size(), m = v2.size();

        while (i < n || j < m)
        {
            s1 = "", s2 = "";
            while (i < n && v1[i] == '0')
                i++;
            while (i < n && v1[i] != '.')
                s1.push_back(v1[i++]);

            while (j < m && v2[j] == '0')
                j++;
            while (j < m && v2[j] != '.')
                s2.push_back(v2[j++]);

            val = comparestrings(s1, s2);
            if (val != 0)
                return val;

            i++, j++;
        }

        return 0;
    }
};
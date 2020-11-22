/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3538/
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    int power(int a, int b)
    {
        if (b == 0)
            return 1;
        int ans = power(a, b / 2);
        return b & 1 ? ans * ans * a : ans * ans;
    }

    int ndig, n;
    int helper(vector<string> &d, string &s, int i)
    {
        if (i == s.size())
            return 1;

        int ans = 0, j = 0;
        while (j < n && d[j][0] < s[i])
            j++;

        ans += j * power(n, ndig - i - 1);
        if (j < n && d[j][0] == s[i])
            ans += helper(d, s, i + 1);

        return ans;
    }

    int atMostNGivenDigitSet(vector<string> &d, int num)
    {
        string s = to_string(num);
        ndig = s.size(), n = d.size();
        int ans = 0;

        for (int i = 1; i <= ndig - 1; i++)
            ans += power(n, i);

        ans += helper(d, s, 0);
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    int power(int a, int b)
    {
        if (b == 0)
            return 1;
        int ans = power(a, b / 2);
        return b & 1 ? ans * ans * a : ans * ans;
    }

    int atMostNGivenDigitSet(vector<string> &digits, int num)
    {
        string s = to_string(num);
        int ndigit = s.size();
        int ans = 0, n = digits.size();

        for (int i = 1; i <= ndigit - 1; i++)
            ans += power(n, i);

        for (int i = 0; i < ndigit; i++)
        {
            bool check = 0;
            for (string &ss : digits)
            {
                if (ss[0] < s[i])
                    ans += power(n, ndigit - i - 1);
                else if (ss[0] == s[i])
                    check = 1;
            }

            if (!check)
                return ans;
        }
        return ans + 1;
    }
};
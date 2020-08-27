/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3436/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//dp
class Solution
{

    int search(vector<int> &days, int x)
    {
        int l = 0, r = days.size() - 1, m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (days[m] == x)
                return m;
            else if (days[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        if (days.size() == 0)
            return 0;

        int n = days.size();
        vector<int> dp(30);

        for (int i = days.front(); i <= days.back(); i++)
        {
            if (search(days, i) != -1)
                dp[i % 30] = min(dp[(i - 1) % 30] + costs[0], min(dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2]));
            else
                dp[i % 30] = dp[(i - 1) % 30];
        }

        return dp[days.back() % 30];
    }
};

//Memo
class Solution
{
public:
    int helper(vector<int> &days, int k, vector<int> &costs, vector<int> &v, int n)
    {
        if (n == 0 || k >= n)
            return 0;

        if (v[k] != -1)
            return v[k];

        int one = INT_MAX, sec = INT_MAX, thir = INT_MAX, count = 0, i = k;
        one = costs[0] + helper(days, k + 1, costs, v, n);

        count = 0;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            count++;
        sec = costs[1] + helper(days, k + count, costs, v, n);

        count = 0;
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            count++;
        thir = costs[2] + helper(days, k + count, costs, v, n);

        v[k] = min(one, min(sec, thir));
        return v[k];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> v(days.size() + 1, -1);
        return helper(days, 0, costs, v, days.size());
    }
};
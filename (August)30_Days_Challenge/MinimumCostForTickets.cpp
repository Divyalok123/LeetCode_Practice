/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3436/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3512/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int ans = 0;
        int i = 0, c1 = 0, n = seats.size();
        while (!seats[i])
            i++;

        ans = i;
        c1 = i;
        while (i < n)
        {
            i++;
            while (i < n && !seats[i])
                i++;
            if (i == n)
                ans = max(ans, n - c1 - 1);
            else
            {
                ans = max(ans, (i - c1) / 2);
                c1 = i;
            }
        }
        return ans;
    }
};
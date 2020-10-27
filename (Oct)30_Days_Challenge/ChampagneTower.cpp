/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3508/
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

/* Solution 2 */
class Solution
{
    vector<vector<double>> v;

public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        if (poured == 0)
            return 0;

        v.assign(102, vector<double>(102, 0));
        v[0][0] = poured;

        for (int i = 1; i <= query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j > 0 && v[i - 1][j - 1] >= 1)
                    v[i][j] += max(0.0, (v[i - 1][j - 1] - 1) / 2.0);
                if (v[i - 1][j] >= 1)
                    v[i][j] += max(0.0, (v[i - 1][j] - 1) / 2.0);
            }
        }

        return min(1.0, v[query_row][query_glass]);
    }
};

/* Solution 1 */
class Solution
{
    int val;
    vector<vector<double>> v;

public:
    double helper(int r, int c)
    {
        if (c < 0 || c > r)
            return 0.0;

        if (r == 0 && c == 0)
        {
            return val;
        }

        if (v[r][c] != -1.0)
            return v[r][c];

        return v[r][c] = max(0.0, (helper(r - 1, c) - 1) / 2.0) + max(0.0, (helper(r - 1, c - 1) - 1) / 2.0);
    }

    double champagneTower(int poured, int query_row, int query_glass)
    {
        if (poured == 0)
            return 0;
        v.assign(102, vector<double>(102, -1.0));
        val = poured;
        return min(1.0, helper(query_row, query_glass));
    }
};
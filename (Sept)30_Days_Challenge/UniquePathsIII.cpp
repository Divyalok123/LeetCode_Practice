/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3466/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(vector<vector<int>> &grid, int n, int m, int i, int j, int &ans, int count)
    {
        if (!isvalid(i, j, n, m) || grid[i][j] == -1 || grid[i][j] == 3)
            return;

        if (grid[i][j] == 2)
        {
            if (count == -1)
                ans++;
            return;
        }

        grid[i][j] = 3;
        count--;
        dfs(grid, n, m, i - 1, j, ans, count);
        dfs(grid, n, m, i + 1, j, ans, count);
        dfs(grid, n, m, i, j - 1, ans, count);
        dfs(grid, n, m, i, j + 1, ans, count);
        count++;
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int si, sj, count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    si = i, sj = j;
                if (grid[i][j] == 0)
                    count++;
            }
        }

        int ans = 0;
        dfs(grid, n, m, si, sj, ans, count);

        return ans;
    }
};
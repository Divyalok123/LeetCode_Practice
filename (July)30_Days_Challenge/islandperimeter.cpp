/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* --------- Solution 2 --------- */
class Solution
{
public:
    int n, m;
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= n || i < 0 || j >= m || j < 0)
            return 1;

        if (grid[i][j] == 0)
            return 1;
        if (grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;
        int count = 0;

        count += dfs(grid, i - 1, j);
        count += dfs(grid, i + 1, j);
        count += dfs(grid, i, j - 1);
        count += dfs(grid, i, j + 1);

        return count;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    count = dfs(grid, i, j);
                    return count;
                }
            }
        }

        return count;
    }
};

/* --------- Solution 1 --------- */
class Solution
{
public:
    int n, m;
    bool isSafe(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int whichone(vector<vector<int>> &grid, int i, int j)
    {
        int count = 0;

        if (!isSafe(i, j - 1) || (isSafe(i, j - 1) && grid[i][j - 1] == 0))
            count++;
        if (!isSafe(i, j + 1) || (isSafe(i, j + 1) && grid[i][j + 1] == 0))
            count++;
        if (!isSafe(i - 1, j) || (isSafe(i - 1, j) && grid[i - 1][j] == 0))
            count++;
        if (!isSafe(i + 1, j) || (isSafe(i + 1, j) && grid[i + 1][j] == 0))
            count++;

        return count;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int one = 0, two = 0, three = 0, four = 0;
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    // cout << "in if" << endl;
                    if (whichone(grid, i, j) == 4)
                        four++;
                    else if (whichone(grid, i, j) == 3)
                        three++;
                    else if (whichone(grid, i, j) == 2)
                        two++;
                    else if (whichone(grid, i, j) == 1)
                        one++;
                }
            }
        }
        // cout << one << " " << two << " " << three << " " << four << " " << endl;
        return one * 1 + two * 2 + three * 3 + four * 4;
    }
};
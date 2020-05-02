/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid.empty())
            return 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < m; j++)
            {
                int temp = grid[i][j];
                grid[i][j] = INT_MAX;
                if(i-1 >= 0 && j >= 0 && i-1 < n && j < m)
                {
                    grid[i][j] = min(grid[i][j], temp + grid[i-1][j]);
                }
                
                if(i >= 0 && j-1 >= 0 && i < n && j-1 < m)
                {
                    grid[i][j] = min(grid[i][j], temp + grid[i][j-1]);
                }
                
                if(grid[i][j] == INT_MAX)
                    grid[i][j] = temp;
            }
        }
        
        return grid[n-1][m-1];
    }
};

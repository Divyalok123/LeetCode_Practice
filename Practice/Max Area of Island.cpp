/*
https://leetcode.com/explore/featured/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>>& choosen, const vector<vector<int>>& grid) {
        int ans = 1;
        choosen[i][j] = 1;

        if(i-1 >= 0 && grid[i-1][j] && !choosen[i-1][j])
            ans += dfs(i-1, j, choosen, grid);
        
        if(i+1 < grid.size() && grid[i+1][j] && !choosen[i+1][j])
            ans += dfs(i+1, j, choosen, grid);
        
        if(j+1 < grid[0].size() && grid[i][j+1] && !choosen[i][j+1])
            ans += dfs(i, j+1, choosen, grid);
        
        if(j-1 >= 0 && grid[i][j-1] && !choosen[i][j-1])
            ans += dfs(i, j-1, choosen, grid);
        
        return ans;
    }
    
    int maxAreaOfIsland(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> choosen(m, vector<bool>(n));
        
        int ans = 0;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    ans = max(ans, dfs(i, j, choosen, grid));
            }
        
        return ans;
    }
};
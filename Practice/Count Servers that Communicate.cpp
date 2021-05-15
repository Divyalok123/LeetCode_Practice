/*
https://leetcode.com/problems/count-servers-that-communicate/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        
        for(int i = 0; i < m; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    count++;
            }
            row[i] = count;
        }
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(grid[j][i])
                    count++;
            }
            col[i] = count;
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && (row[i] > 1 || col[j] > 1))
                    ans++;
            }
        }
        
        return ans;
    }
};
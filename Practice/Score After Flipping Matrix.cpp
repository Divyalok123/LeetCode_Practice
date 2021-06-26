/*
https://leetcode.com/problems/score-after-flipping-matrix/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//without manipulating matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int curr = (1 << (m-1));
        int ans = n * curr;
        for(int j = 1; j < m; j++) {
            int count = 0;
            for(int i = 0; i < n; i++)
                count += grid[i][j] == grid[i][0];
            
            if(count < (n+1)/2)
                count = n - count;
            
            curr >>= 1;
            ans += count * curr;
        }
        
        return ans;
    }
};

// simple solution
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++)
                    grid[i][j] ^= 1;
            }
        }
        
        int curr = (1 << (m-1));
        int ans = n * curr;
        for(int j = 1; j < m; j++) {
            int count = 0;
            for(int i = 0; i < n; i++)
                count += grid[i][j];
            
            if(count < (n+1)/2)
                count = n - count;
            
            curr >>= 1;
            ans += count * curr;
        }
        
        return ans;
    }
};
/*
https://leetcode.com/problems/largest-1-bordered-square/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Counting continuous ones
class Solution {
public:
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        int left[n][m], top[n][m];
        memset(left, 0, sizeof(left));
        memset(top, 0, sizeof(top));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    ans = 1;
                    left[i][j] = j==0 ? 1 : left[i][j-1] + 1;
                    top[i][j] = i==0 ? 1 : top[i-1][j] + 1;
                }
            }
        
        for(int i = n-1; i >= 1; i--) {
            for(int j = m-1; j >= 1; j--) {
                if(grid[i][j] == 0) continue;
                int size = min(left[i][j], top[i][j]);
                while(size > ans) {
                    if(left[i-size+1][j] >= size && top[i][j-size+1] >= size)
                        ans = size;
                    size--;
                }
            }
        }
                  
        return ans*ans;
    }
    
};

// Improved 
class Solution {
public:
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        int counts[n+1][m+1];
        memset(counts, 0, sizeof(counts));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                counts[i+1][j+1] = counts[i][j+1] + counts[i+1][j] - counts[i][j] + (grid[i][j] == 0);
        
        for(int i = n; i >= 2; i--) {
            for(int j = m; j >= 2; j--) {
                if(grid[i-1][j-1] == 0) 
                    continue;
            
                int minval = min(i, j);
                int indi = i-minval, indj = j-minval;
                while(indi <= i-2 && indj <= j-2 && ans < (i-indi)) {
                    if(grid[indi][indj] != 0) {
                        int zeroes = counts[i][j]+counts[indi][indj]-counts[indi][j]-counts[i][indj];
                        int zeroesin = 0;
                        if(indi < i-2)
                            zeroesin = counts[i-1][j-1]+counts[indi+1][indj+1]-counts[indi+1][j-1]-counts[i-1][indj+1];
                        int rem = zeroes-zeroesin;
                        if(rem == 0) 
                            ans = i-indi;
                    }
                    indi++, indj++;
                }
            }
        }
                  
        if(ans == 0) ans = (counts[n][m] != n*m);
        return ans*ans;
    }
    
};

// naive solution - O(n^3)
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> counts(n+1, vector<int>(m+1));
        int ans = (grid[0][0]==1);
        counts[1][1] = !ans;
        
        for(int i = 1; i < m; i++) {
            counts[1][i+1] = counts[1][i] + (grid[0][i] == 0);
            if(grid[0][i] && !ans) ans = 1;
        }
        
        for(int i = 1; i < n; i++) {
            counts[i+1][1] = counts[i][1] + (grid[i][0] == 0);
            if(grid[i][0] && !ans) ans = 1;
        }
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                counts[i+1][j+1] = counts[i][j+1] + counts[i+1][j] - counts[i][j] + (grid[i][j] == 0);
        
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= m; j++) {
                if(grid[i-1][j-1] == 0) continue;
                if(!ans) ans = 1;
                if(i == 2 || j == 2) {
                    int zeroes = counts[i][j]+counts[i-2][j-2]-counts[i-2][j]-counts[i][j-2];
                    if(zeroes == 0) {
                        if(ans < 4)
                            ans = 4;
                        else if(i == 2)
                            break;
                    }
                } else {
                    int minval = min(i, j);
                    int indi = i-minval, indj = j-minval;
                    while(indi <= i-2 && indj <= j-2) {
                        int zeroes = counts[i][j]+counts[indi][indj]-counts[indi][j]-counts[i][indj];
                        int zeroesin = 0;
                        if(indi < i-2)
                        zeroesin = counts[i-1][j-1]+counts[indi+1][indj+1]-counts[indi+1][j-1]-counts[i-1][indj+1];
                        int rem = zeroes-zeroesin;
                        if(rem == 0)
                        {
                            ans = max(ans, (i-indi)*(i-indi));
                            break;
                        }
                        
                        indi++, indj++;
                    }
                }
            }
        }
                    
        return ans;
    }
};
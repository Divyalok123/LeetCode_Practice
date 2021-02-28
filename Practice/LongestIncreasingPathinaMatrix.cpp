/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1 (DFS + Memo)
class Solution {
public:
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    
    bool check(int i , int j) {
        return i >= 0 && j >= 0 && i < n && j < m;    
    }
    
    vector<vector<int>> memo;
    
    int dfs(int i, int j, vector<vector<int>>& mat) {
        if(memo[i][j] != 0) 
            return memo[i][j];
        
        int ans = 1;
        for(int l = 0; l < 4; l++) {
            int ni = i + moves[l][0];
            int nj = j + moves[l][1];
            
            if(check(ni, nj) && mat[ni][nj] > mat[i][j]) {
                int v = 1 + dfs(ni, nj, mat);
                if(ans < v) ans = v;
            }
        }
        
        return memo[i][j] = ans;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        memo.resize(n, vector<int>(m));
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int c = dfs(i, j, mat);    
                if(c > ans) ans = c;
            }
        }
        
        return ans;
    }
};
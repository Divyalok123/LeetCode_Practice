/*
https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//union-find
class Solution {
public:
    int n, m;
    int moves[6][2][2] = {{{0, -1}, {0, 1}}, 
                          {{-1, 0}, {1, 0}}, 
                          {{0, -1}, {1, 0}}, 
                          {{0, 1}, {1, 0}}, 
                          {{0, -1}, {-1, 0}}, 
                          {{-1, 0}, {0, 1}}};
    
    vector<int> parent, rank;
    
    int find(int i) {
        return i == parent[i] ? i : parent[i] = find(parent[i]);
    }
    
    void un(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if(pi == pj) return;
        
        int ri = rank[pi], rj = rank[pj];
        
        if(ri < rj)
            swap(pi, pj);
        
        parent[pj] = pi;
        
        if(ri == rj)
            rank[pi]++;
    }
    
    
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        parent.resize(n * m);
        rank.resize(n * m);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 2; k++) {
                    int ni = i + moves[grid[i][j]-1][k][0];
                    int nj = j + moves[grid[i][j]-1][k][1];

                    if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                    bool check = false;
                    for(int l = 0; l < 2; l++) {
                        if(ni + moves[grid[ni][nj]-1][l][0] == i && nj + moves[grid[ni][nj]-1][l][1] == j)
                            check = true;
                    }
                    
                    if(check) un(i * m + j, ni * m + nj);
                }
            }
        }
        
        return find(0) == find(n*m-1);
    }
};

//dfs
class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    int moves[6][2][2] = {{{0, -1}, {0, 1}}, 
                          {{-1, 0}, {1, 0}}, 
                          {{0, -1}, {1, 0}}, 
                          {{0, 1}, {1, 0}}, 
                          {{0, -1}, {-1, 0}}, 
                          {{-1, 0}, {0, 1}}};
    
    
    
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        
        if(vis[i][j]) return 0;
        
        if(i == n-1 && j == m-1) return 1;
        
        bool ans = false;
        vis[i][j] = 1;
        for(int k = 0; k < 2; k++) {
            int ni = i + moves[grid[i][j]-1][k][0];
            int nj = j + moves[grid[i][j]-1][k][1];
            
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            
            bool check = false;
            for(int l = 0; l < 2; l++) {
                if(ni + moves[grid[ni][nj]-1][l][0] == i && nj + moves[grid[ni][nj]-1][l][1] == j)
                    check = true;
            }
            
            if(check)
                ans |= dfs(grid, ni, nj);
        }
        
        return ans;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m));
        return dfs(grid, 0, 0);
    }
};
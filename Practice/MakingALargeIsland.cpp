/*
https://leetcode.com/problems/making-a-large-island/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 2 (O(N^2), Union-Find)


// Solution 1 (O(N^2), DFS)
class Solution {
public:
    void print(vector<vector<pair<int, int>>>& forevery, int n) {
        cout << "ANS TABLE" << endl;
        for(int i = 0; i < n; i++) {
            cout << "[";
            for(int j = 0; j < n; j++) {
                cout << "{" << forevery[i][j].first << ", " << forevery[i][j].second << "}";
            }
            cout << "]" << endl;
        }
    }
    
    int points[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    void dfs1(vector<vector<bool>>& check, vector<vector<int>>& grid, int i, int j, int& q, int n) {
        if(i < n && j < n && i >= 0 && j >= 0) {
            if(grid[i][j] == 0 || check[i][j]) return;
            
            check[i][j] = 1;
            q++;
            
            for(int k = 0; k < 4; k++) {
                int newi = i + points[k][0];
                int newj = j + points[k][1];
                dfs1(check, grid, newi, newj, q, n);
            }
        }
    }
    
    void dfs2(vector<vector<pair<int, int>>>& ans, vector<vector<int>>& grid, int i, int j, int val, int n, int iland) {
        if(i < n && j < n && i >= 0 && j >= 0) {
            if(grid[i][j] == 0 || ans[i][j].first != -1) return;
            
            ans[i][j] = {val, iland};
            
            for(int k = 0; k < 4; k++) {
                int newi = i + points[k][0];
                int newj = j + points[k][1];
                dfs2(ans, grid, newi, newj, val, n, iland);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<bool>> ischeck(n, vector<bool>(n, 0));
        vector<vector<pair<int, int>>> forevery(n, vector<pair<int, int>>(n, make_pair(-1, -1)));
        int ans = 0, iland = 1;
        vector<pair<int, int>> zeroes;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ischeck[i][j] == 0 && grid[i][j] == 1) {
                    
                    int q = 0;
                    dfs1(ischeck, grid, i, j, q, n);
                    if(q > ans) ans = q;
                    
                    dfs2(forevery, grid, i, j, q, n, iland);
                    iland++;
                }
                
                if(grid[i][j] == 0)
                    zeroes.push_back({i, j});
            }
        }
        
        if(ans == n*n) return ans;
        
        for(auto [i, j]: zeroes) {
            unordered_set<int> s;
            int tot = 0;
            for(int k = 0; k < 4; k++) {
                int newi = i + points[k][0];
                int newj = j + points[k][1];

                if(newi >= 0 && newj >= 0 && newi < n && newj < n) {
                    auto point = forevery[newi][newj]; 
                    if(point.second != -1 && s.find(point.second) == s.end()) {
                        tot += point.first;
                        s.insert(point.second);
                    }
                }
            }
            if(tot > ans) 
                ans = tot;
        }
        
        if(ans < n*n) ans++;
        return ans;
    }
};

/*

[[1,0],[0,1]]
[[1,1],[1,0]]
[[1,1],[1,1]]
[[0,0],[0,0]]
[[1,0,1],[0,0,0],[0,1,1]]
[[0,1,1,0,0],[0,0,1,1,0],[1,1,0,1,1],[1,1,0,1,0],[0,1,0,0,1]]

*/
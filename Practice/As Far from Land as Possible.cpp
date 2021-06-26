/*
https://leetcode.com/problems/as-far-from-land-as-possible/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool vis[n][n];
        memset(vis, 0, sizeof(vis));
        
        using pii = pair<int, int>;
        queue<pii> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                if(grid[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
        }
        
        if(q.size() == 0 || q.size() == n*n) 
            return -1;
        
        int ans = -1;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto [fi, fj] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int newi = fi + moves[i][0];
                    int newj = fj + moves[i][1];
                    
                    if(newi == -1 || newj == -1 || 
                       newi == n || newj == n || 
                       vis[newi][newj] || grid[newi][newj]) continue;
                    
                    vis[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
            
            ans++;
        }
        
        
        return ans;
    }
};
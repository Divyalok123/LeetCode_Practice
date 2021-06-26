/*
https://leetcode.com/problems/map-of-highest-peak/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// bfs
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<array<int, 2>> q;
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        int moves[4][2] = {{-1, 0},{1, 0},{0, 1},{0, -1}};
        int h = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto f = q.front();
                q.pop();
                
                int i = f[0], j = f[1];
                isWater[i][j] = h;
                
                for(int k = 0; k < 4; k++) {
                    int ni = i + moves[k][0];
                    int nj = j + moves[k][1];
                    
                    if(ni < m && nj < n && ni >= 0 && nj >= 0) {
                        if(vis[ni][nj] == 0) {
                            vis[ni][nj] = 1;
                            q.push({ni, nj});
                        }
                    }
                }
            }
            h++;
        }
        
        return isWater;
    }
};
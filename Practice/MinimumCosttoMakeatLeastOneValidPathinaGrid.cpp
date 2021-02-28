/*
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//Solution 3 (DFS + BFS) (O(N))
class Solution {
public:
    int n, m;
    bool isfine(int i, int j) {
        return i < n && j < m && i >= 0 && j >= 0;
    }
    
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(int i, int j, vector<vector<int>>& dp, queue<vector<int>>& pq, vector<vector<int>>& g, int k) {
        if(!isfine(i, j) || dp[i][j] != INT_MAX) return;
        dp[i][j] = k;
        pq.push({i, j});
        dfs(i+moves[g[i][j]-1][0], j + moves[g[i][j]-1][1], dp, pq, g, k);
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if(n == m && n == 1) return 0;
        
        int newi, newj, z;
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        queue<vector<int>> pq;
        int k = 0;
        dfs(0,0,dp,pq,grid,k);
        
        while(pq.size()) {
            int s = pq.size();
            k++;
            while(s--) {
                vector<int> v = pq.front();
                pq.pop();
                int i = v[0], j = v[1];
                for(int l = 0; l < 4; l++) {
                    newi = i + moves[l][0];
                    newj = j + moves[l][1];
                    dfs(newi, newj, dp, pq, grid, k);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};

//Solution 2 (0-1 BFS) (O(N))
class Solution {
public:
    int n, m;
    bool isfine(int i, int j) {
        return i < n && j < m && i >= 0 && j >= 0;
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if(n == m && n == 1) return 0;
        
        int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int newi, newj, z;
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        deque<vector<int>> pq;
        dp[0][0] = 0;
        pq.push_back({0, 0, 0});
        
        while(pq.size()) {
            vector<int> v = pq.front();
            pq.pop_front();
            
            int k = v[0], i = v[1], j = v[2];
            // cout << "k: " << k << " i: " << i << " j: " << j << endl;
            if(i == n-1 && j == m-1) 
                return k;
            
            for(int l = 0; l < 4; l++) {
                newi = i + moves[l][0];
                newj = j + moves[l][1];
                
                if(isfine(newi, newj)) {
                    if(l == grid[i][j]-1) {
                        if(dp[newi][newj] > k) {
                            dp[newi][newj] = k;
                            pq.push_front({k, newi, newj});
                            // cout << "pushed at front," << " k: " << k << " newi: " << newi << " newj: " << newj << endl;
                        }
                    } else {
                        if(dp[newi][newj] > k+1) {
                            dp[newi][newj] = k+1;
                            pq.push_back({k+1, newi, newj});
                            // cout << "pushed at back," << " k: " << k+1 << " newi: " << newi << " newj: " << newj << endl;
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};

//Solution 1 (BFS) (O(N*log(N)))
class Solution {
public:
    int n, m;
    bool isfine(int i, int j) {
        return i < n && j < m && i >= 0 && j >= 0;
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if(n == m && n == 1) return 0;
        
        class cmp {
            public:
                bool operator()(const vector<int>& a, const vector<int>& b){
                    return a[0] > b[0];
                }
        };
        
        int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int newi, newj, z;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        
        while(pq.size()) {
            vector<int> v = pq.top();
            pq.pop();
            
            int k = v[0], i = v[1], j = v[2];
            if(i == n-1 && j == m-1) 
                return k;
            
            if(dp[i][j] < k) continue;
            for(int l = 0; l < 4; l++) {
                newi = i + moves[l][0];
                newj = j + moves[l][1];
                
                if(isfine(newi, newj)) {
                    z = (l == (grid[i][j]-1)) ? k : k+1;
                    if(dp[newi][newj] > z) {
                        pq.push({z, newi, newj});
                        dp[newi][newj] = z;
                    }
                }
            }
        }
        
        return 0;
    }
};
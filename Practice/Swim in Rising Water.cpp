/*
https://leetcode.com/problems/swim-in-rising-water/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <numeric>
#include <queue>
using namespace std;

//union-find (O(n*n))
class Solution {
public:
    
    vector<int> rank, parent;
    
    int find(int a) 
    {
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b)  {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[a], rb = rank[b];
            
            if(ra < rb)
                swap(pa, pb);
            else if(ra == rb)
                rank[pa]++;
            
            parent[pb] = pa;
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        rank.resize(n*n);
        parent.resize(n*n);
        iota(parent.begin(), parent.end(), 0);
        
        int ans = 0;
        
        vector<pair<int, int>> v(n*n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v[grid[i][j]] = {i, j};
            }
        }
        
        int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < n*n; i++) {
            auto [a, b] = v[i];
            
            for(int j = 0; j < 4; j++) {
                
                int newi = a + moves[j][0];
                int newj = b + moves[j][1];
                
                if(newi >= 0 && newi < n && newj < n && newj >= 0 && grid[newi][newj] <= ans)
                    un(a*n + b, newi*n + newj);
            }
            
            ans++;
            if(find(0) == find(n*n-1))
                break;
        }
        
        return ans-1;
    }
};

//dijkstra (O(n*nlogn))
class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<bool>> store(n, vector<bool>(n, 0));
        store[0][0] = grid[0][0];
        
        int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        using pii = pair<int, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(grid[0][0], make_pair(0,0)));
        
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            
            int val = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            if(i == n-1 && j == n-1)
                return val;
            
            for(int k = 0; k < 4; k++) {
                int newi = i + moves[k][0];
                int newj = j + moves[k][1];
                
                if(newi >= 0 && newi < n && newj < n && newj >= 0 && !store[newi][newj]) {
                    int newval = max(val, grid[newi][newj]);
                    store[newi][newj] = 1;
                    pq.push(make_pair(newval, make_pair(newi, newj)));
                }
            }
        }
        
        return store[n-1][n-1];        
    }
};

//dfs with binary search Nlog(N) , N->n*n
class Solution {
public:
    
    bool dfs(int t, vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& vis) {
        if(i == n-1 && j == n-1) 
            return grid[i][j] <= t;
        
        if(vis[i][j])
            return 0;
        
        vis[i][j] = 1;
        
        int a = 0, b = 0, c = 0, d = 0;
        
        if(i < n-1 && grid[i+1][j] <= t)
            a = dfs(t, grid, i+1, j, n, vis);
        
        if(i > 0 && grid[i-1][j] <= t)
            b = dfs(t, grid, i-1, j, n, vis);
        
        if(j > 0 && grid[i][j-1] <= t)
            c = dfs(t, grid, i, j-1, n, vis);
        
        if(j < n-1 && grid[i][j+1] <= t)
            d = dfs(t, grid, i, j+1, n, vis);
        
        return a || b || c || d;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = n*n;
        
        while(l < r) {
            int m = (l + r)/2;
            
            vector<vector<bool>> vis(n, vector<bool>(n));
            
            if(dfs(m, grid, 0, 0, n, vis))
                r = m;
            else 
                l = m+1;
        }
        
        return l;
    }
};
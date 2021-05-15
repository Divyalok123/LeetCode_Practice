/*
https://leetcode.com/problems/regions-cut-by-slashes/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// union-find
class Solution {
public:
    vector<int> rank, p;
    
    int find(int a) {
        return a == p[a] ? a : p[a] = find(p[a]);
    }
    
    void u(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];

            if(ra < rb)
                swap(pa, pb);
            
            p[pb] = pa;
            
            if(ra == rb)
                rank[pa]++;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int lim = 4*n*n;
        
        p.resize(lim);
        rank.resize(lim);
        
        iota(p.begin(), p.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int a = 4*n*i + 4*j, b = a + 1, c = a + 2, d = a + 3;
                
                if(grid[i][j] != '\\')  
                    u(a, b), u(d, c);
                
                
                if(grid[i][j] != '/') 
                    u(a, d), u(b, c);
                
                if(i < n-1) 
                    u(c, c + 4*(n-1) + 2);
                
                if(j < n-1) 
                    u(d, d + 2);
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < lim; i++) 
            if(find(i) == i) 
                ans++;
        
        return ans;
    }
};

// dfs
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& g, int n) {
        if(g[i][j]) return;
        
        g[i][j] = 1;
        
        if(i+1 < n)
            dfs(i+1, j, g, n);
        
        if(i-1 >= 0)
            dfs(i-1, j, g, n);
        
        if(j+1 < n)
            dfs(i, j+1, g, n);
        
        if(j-1 >= 0)
            dfs(i, j-1, g, n);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        vector<vector<bool>> g(n*3, vector<bool>(3*n));
        for(int i = 0; i < grid.size(); i++) {
            int j = 0, gi = 0;
            while(j < grid[i].size()) {
                // cout << "i: " << i << " j: " << j << " grid[" << i << "][" << j << "]: " << grid[i][j] << endl;
                    
                if(grid[i][j] == '/') {
                    g[3*i+2][3*gi] = 1;
                    g[3*i+1][3*gi+1] = 1;
                    g[3*i][3*gi+2] = 1;
                } else if(grid[i][j] == '\\') {
                    g[3*i][3*gi] = 1;
                    g[3*i+1][3*gi+1] = 1;
                    g[3*i+2][3*gi+2] = 1;
                }
                j++, gi++;
            }
        }
        
//         cout << "g" << endl;
//         for(auto& gg: g) {
//             for(auto j: gg)
//                 cout << j << " ";
//             cout << endl;
//         }
        
        int ans = 0;
        for(int i = 0; i < 3*n; i++) {
            for(int j = 0; j < 3*n; j++) {
                if(g[i][j] == 0)
                    ans++, dfs(i, j, g, 3*n);
            }
        }
        
        return ans;
    }
};
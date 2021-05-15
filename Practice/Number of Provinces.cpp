/*
https://leetcode.com/problems/number-of-provinces/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

//union-find
class Solution {
public:
    
    vector<int> p, rank;
    
    int find(int a) {
        return p[a] == a ? a : p[a] = find(p[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                swap(pa, pb);
            
            p[pb] = pa;
            
            if(ra == rb)
                rank[ra]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        rank.resize(n);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isConnected[i][j])
                    un(i, j);
            }
        }
        
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(find(i));
        }
        
        return s.size();
    }
};

//dfs
class Solution {
public:
    
    void dfs(vector<vector<int>>& g, int i, vector<bool>& vis) {
        vis[i] = 1;
        
        for(int& j: g[i])
            if(!vis[j])
                dfs(g, j, vis);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j])
                    g[i].push_back(j);
            }
        }
        
        vector<bool> vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0)
                ans++, dfs(g, i, vis);
        }
        
        return ans;
    }
};
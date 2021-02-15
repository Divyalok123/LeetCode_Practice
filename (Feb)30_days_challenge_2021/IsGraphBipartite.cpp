/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3639/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Solution 2 (DFS)
class Solution {
public:
    bool dfs(vector<vector<int>>& g, int node, vector<bool>& vis, vector<int>& val) {
        vis[node] = 1;
        for(int& i: g[node]) {
            if(val[i] == val[node]) return 0;
            if(!vis[i]) {
                val[i] = val[node]^1;
                if(!dfs(g, i, vis, val))
                    return 0;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> val(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] || !graph[i].size()) continue;
            val[i] = 0;
            if(!dfs(graph, i, vis, val))   
                return 0;
        }
        
        return 1;
    }
};

// Solution 1 (BFS)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<int> val(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] || !graph[i].size()) continue;
            queue<int> q;
            q.push(i);  
            val[0] = 1;
            int t = 1;
            while(q.size()) {
                int sz = q.size();
                while(sz--) {
                    int el = q.front();
                    q.pop();

                    vis[el] = 1;

                    for(int& i: graph[el]) {
                        if(!vis[i]) {
                            if(val[i] == t) return 0;
                            val[i] = t^1;
                            q.push(i);
                        }
                    }
                }
                t ^= 1;
            }
        }
        
        return 1;
    }
};
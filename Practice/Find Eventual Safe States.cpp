/*
https://leetcode.com/problems/find-eventual-safe-states/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//bfs
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> ans;
        queue<int> q;
        vector<vector<int>> reverse(n);
        vector<int> degree(n);
        
        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 0)
                q.push(i);
            else 
                for(int& j: graph[i]) {
                    reverse[j].push_back(i);
                    degree[i]++;
                }
        }
        
        
        while(q.size()) {
            int f = q.front();
            q.pop();
            
            ans.push_back(f);
            
            for(int& nex: reverse[f]) {
                degree[nex]--;
                if(degree[nex] == 0) {
                    q.push(nex);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//dfs
class Solution {
public:
    vector<bool> vis; //visited
    vector<bool> is; //isSafe
    
    void dfs(int node, vector<vector<int>>& graph) {
        
        vis[node] = 1;
        bool check = true;
        for(int& nextt: graph[node]) {
            if(vis[nextt]) {
                if(!is[nextt])
                    check = false;
                continue;
            }
            
            dfs(nextt, graph);
            if(!is[nextt])
                check = false;
        }
        
        if(check) 
            is[node] = 1;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n);
        is.resize(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0)
                dfs(i, graph);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(is[i])
                ans.push_back(i);
        
        return ans;
    }
};
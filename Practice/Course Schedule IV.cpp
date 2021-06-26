/*
https://leetcode.com/problems/course-schedule-iv/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// dfs + memo
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<int>> dp;
    
    bool dfs(int u, int v, vector<vector<int>>& graph) {
        if(u == v) return 1;
        
        if(dp[u][v] != -1)
            return dp[u][v];
        
        for(auto& nex: graph[u]) {
            if(dfs(nex, v, graph)) {
                return dp[u][v] = 1;
            }
        }
        
        return dp[u][v] = 0;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        
        vector<vector<int>> graph(n);
        dp.resize(n, vector<int>(n, -1));
        for(auto& i: prerequisites) {
            int u = i[0], v = i[1];
            graph[u].push_back(v);
        }
        
        int qs = queries.size();
        vector<bool> ans(qs);
        int i = 0;
        for(auto& q: queries) {
            if(dfs(q[0], q[1], graph))
                ans[i] = 1;
            i++;
        }
        
        return ans;
    }
};

// floyd warshall
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        
        vector<vector<bool>> connec(n, vector<bool>(n));
        for(auto& p: prerequisites)
            connec[p[0]][p[1]] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(connec[j][i] && connec[i][k])
                        connec[j][k] = 1;
                }
            }
        }
        
        int sz = queries.size();
        vector<bool> ans(sz);
        for(int i = 0; i < sz; i++) {
            int u = queries[i][0], v = queries[i][1];
            if(connec[u][v])
                ans[i] = 1;
        }
        
        return ans;
    }
};

//topological sort
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        
        for(auto& i: prerequisites) {
            graph[i[0]].push_back(i[1]);
            degree[i[1]]++;
        }
        
        unordered_map<int, unordered_set<int>> preq;
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 0) {
                q.push(i);
            }
        
        while(q.size()) {
            int f = q.front();
            q.pop();
            
            for(int& nex: graph[f]) {
                preq[nex].insert(f);
                preq[nex].insert(preq[f].begin(), preq[f].end());
                if(--degree[nex] == 0) {
                    q.push(nex);
                }
            }
        }
        
        int qs = queries.size();
        vector<bool> ans(qs);        
        for(int i = 0; i < qs; i++) {
            auto& ss = preq[queries[i][1]];
            if(ss.find(queries[i][0]) != ss.end())
                ans[i] = 1;
        }
        
        return ans;
    }
};
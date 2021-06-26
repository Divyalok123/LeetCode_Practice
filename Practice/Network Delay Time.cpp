/*
https://leetcode.com/problems/network-delay-time/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

//bellman-ford
class Solution {
    vector<int> vis;
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        if(t < n-1) return -1;
        
        vis.resize(n+1, INT_MAX);
        vis[k] = 0;
        
        for(int i = 0; i < n-1; i++) {
            for(auto& j: times) {
                int u = j[0], v = j[1], w = j[2];
                
                if(vis[u] != INT_MAX && vis[v] > vis[u] + w)
                    vis[v] = vis[u] + w;
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == INT_MAX) return -1;
            if(ans < vis[i])
                ans = vis[i];
        }
        
        return ans;
    }
};

// normal bfs
class Solution {
    vector<int> vis;
    vector<vector<array<int, 2>>> nodes;
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        if(t < n-1) return -1;
        
        vis.resize(n+1, INT_MAX);
        nodes.resize(n+1);
        
        for(auto& i: times)
            nodes[i[0]].push_back({i[1], i[2]});
        
        using pii = pair<int, int>;
        queue<pii> q;
        
        q.push({0, k});
        while(q.size()) {
            pii front = q.front();
            q.pop();
            
            vis[front.second] = min(vis[front.second], front.first);
            
            for(auto& node: nodes[front.second]) {
                if(vis[node[0]] > front.first + node[1]) {
                    q.push({front.first + node[1], node[0]});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == INT_MAX) return -1;
            if(ans < vis[i])
                ans = vis[i];
        }
        
        return ans;
    }
};

//dfs
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
    vector<int> vis;
    vector<vector<array<int, 2>>> nodes;
public:
    void dfs(int currnode, int curr) {
        if(vis[currnode] <= curr)
            return;
        
        vis[currnode] = curr;
        for(auto& node: nodes[currnode])
            if(curr+node[1] < vis[node[0]])
                dfs(node[0], curr + node[1]);
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        if(t < n-1) return -1;
        
        vis.resize(n+1, INT_MAX);
        nodes.resize(n+1);
        
        for(auto& i: times)
            nodes[i[0]].push_back({i[1], i[2]});
        
        dfs(k, 0);  
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == INT_MAX) return -1;
            if(ans < vis[i])
                ans = vis[i];
        }
        
        return ans;
    }
};

// priority-queue solution (BFS)
class Solution {
    vector<int> vis;
    vector<vector<array<int, 2>>> nodes;
    int count;
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        if(t < n-1) return -1;
        
        vis.resize(n+1, -1);
        nodes.resize(n+1);
        
        for(auto& i: times)
            nodes[i[0]].push_back({i[1], i[2]});
        
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        
        minheap.push({0, k});
        while(minheap.size()) {
            pii top = minheap.top();
            minheap.pop();
            
            if(vis[top.second] != -1) continue;
            
            // cout << "top.s: " << top.second << " top.f: " << top.first << endl;
            vis[top.second] = top.first;
            
            for(auto& node: nodes[top.second]) {
                if(vis[node[0]] == -1) {
                    // cout << "passing node: " << node[0] << " value: " << top.first + node[1] << endl;
                    minheap.push({top.first + node[1], node[0]});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == -1) return -1;
            if(ans < vis[i])
                ans = vis[i];
        }
        
        return ans;
    }
};
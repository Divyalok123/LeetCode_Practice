/*
https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;

// without dfs
class Solution {
public:
    #define MOD 1000000007
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 2>>> graph(n+1);
        
        for(auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        vector<int> dist(n+1, INT_MAX);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n});
        dist[n] = 0;
        vector<int> count(n+1);
        count[n] = 1;
        
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            
            int node = t.second, dpath = t.first;
            if(dpath != dist[node]) continue;
            
            for(auto& nex: graph[node]) {
                if(dist[nex[0]] > dist[node])
                    count[nex[0]] = (count[nex[0]] + count[node]) %MOD;
                if(dist[nex[0]] > dpath + nex[1]) {
                    dist[nex[0]] = dpath + nex[1];
                    pq.push({dist[nex[0]], nex[0]});
                }
            }
        }
        
        return count[1];
    }
};

// dijkstra
class Solution {
public:
    #define MOD 1000000007
    int dfs(int node, int end, vector<vector<array<int, 2>>>& graph, vector<int>& dp, vector<int>& dist) {
        if(node == end) return 1;
        
        int& ans = dp[node];
        if(ans != -1) return ans;

        ans = 0;
        for(auto& nex: graph[node])
            if(dist[nex[0]] < dist[node])
                ans = (ans + dfs(nex[0], end, graph, dp, dist))%MOD;
        
        return ans;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 2>>> graph(n+1);
        
        for(auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        vector<int> dist(n+1, INT_MAX);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n});
        dist[n] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            
            int node = t.second, dpath = t.first;
            if(dpath != dist[node]) continue;
            
            for(auto& nex: graph[node]) {
                if(dist[nex[0]] > dpath + nex[1]) {
                    dist[nex[0]] = dpath + nex[1];
                    pq.push({dist[nex[0]], nex[0]});
                }
            }
        }
        
//         cout << "DIST: ";
//         for(auto& i: dist)
//             cout << i << " ";
//         cout << endl;
        
        vector<int> dp(n+1, -1);
        dfs(1, n, graph, dp, dist);
        
        return dp[1];
    }
};
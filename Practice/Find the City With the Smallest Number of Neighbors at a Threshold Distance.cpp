/*
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//dijkstra single source shortest path
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
                
        using pii = pair<int, int>;
        vector<pii> adj[n];
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(auto& i: edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        // cout << "dist" << endl;
        // for(auto& i: dist)
        // {
        //     for(auto& j: i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        
        
        int count = INT_MAX, city = -1;
        for(int i = 0; i < n; i++) {
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, i});
            // cout << "i: " << i << endl;
            while(pq.size()) {
                auto top = pq.top();
                pq.pop();
                
                int thisnode = top.second, val = top.first;
                // cout << "thisnode: " << thisnode << " val: " << val << endl;
                
                if(dist[i][thisnode] < val) continue;
                for(auto& node: adj[thisnode]) {
                    // cout << "node: " << node.first << " left: " << dist[i][node.first] << " right: " << val + node.second << endl;
                    if(dist[i][node.first] > val + node.second) {
                        dist[i][node.first] = val + node.second;
                        // cout << "pushing " << node.first << endl;
                        pq.push({dist[i][node.first], node.first});
                    }
                } 
            }
            
            int thiscount = 0;
            for(int j = 0; j < n; j++) {
                // cout << dist[i][j] << " ";
                if(dist[i][j] <= distanceThreshold)
                    thiscount++;
            }
            // cout << endl;
            
            if(thiscount <= count) {
                count = thiscount;
                city = i;
            }
            
        }
        
        
        return city;
    }
};

//floyd warshall all pairs shortest path
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto& i: edges) {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(dist[j][i] != INT_MAX && dist[i][k] != INT_MAX 
                       && dist[j][k] > dist[j][i] + dist[i][k])
                        dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
        
//         cout << "DIST" << endl;
//         for(auto& i: dist) {
//             for(auto& j: i)
//                 cout << j << ' ';
//             cout << endl;
//         }
        
        
        int count = INT_MAX, city = -1;
        for(int i = 0; i < n; i++) {
            int thiscount = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold)
                    thiscount++;
            }
            
            if(thiscount <= count) {
                count = thiscount;
                city = i;
            }
        }
        
        return city;
    }
};

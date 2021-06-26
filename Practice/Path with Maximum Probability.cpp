/*
https://leetcode.com/problems/path-with-maximum-probability/
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// dijkstra
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        double dist[n];
        memset(dist, 0, sizeof(dist));
        
        int i = 0;
        for(auto& edge: edges)
        {
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
            i++;
        }
        
        using pdi = pair<double, int>;
        priority_queue<pdi> q;
        q.push({1.0, start});
        
        while(q.size()) {
            auto [prob, node] = q.top();
            q.pop();
            
            if(dist[node] < prob)
                dist[node] = prob;

            if(node == end) break;
            
            for(auto [nex, nexprob]: graph[node]) {
                if(dist[nex] < nexprob * prob) {
                    dist[nex] = nexprob*prob;
                    q.push({dist[nex], nex});
                }
            }
        }
        
        return dist[end];
    }
};

//simple bfs
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        vector<double> dist(n, 0);
        int i = 0;
        for(auto& edge: edges)
        {
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
            i++;
        }
        
        using pdi = pair<double, int>;
        queue<pdi> q;
        q.push({1.0, start});
        
        while(q.size()) {
            auto [prob, node] = q.front();
            q.pop();
            
            if(dist[node] < prob)
                dist[node] = prob;
            
            for(auto [nex, nexprob]: graph[node]) {
                if(dist[nex] < nexprob * prob) {
                    dist[nex] = nexprob*prob;
                    q.push({dist[nex], nex});
                }
            }
        }
        
        return dist[end];
    }
};
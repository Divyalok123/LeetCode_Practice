/*
https://leetcode.com/problems/maximal-network-rank/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// using largest and second largest - O(n)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        
        for(auto& i: roads) {
            int u = i[0], v = i[1];
            degree[u]++;
            degree[v]++;
        }
        
        int maxx = 0, smaxx = 0;
        for(int i = 0; i < n; i++) {
            if(degree[i] == maxx) continue;
            else if(degree[i] > maxx) {
                smaxx = maxx;
                maxx = degree[i];
            } else if(degree[i] > smaxx)
                smaxx = degree[i];
        }
        
        int maxxc = 0, smaxxc = 0;
        for(int i = 0; i < n; i++) {
            if(degree[i] == maxx)
                maxxc++;
            else if(degree[i] == smaxx)
                smaxxc++;
        }

        int count = 0;
        if(maxxc == 1) {
            for(auto& road: roads) {
                int u = road[0], v = road[1];
                if(degree[u] == maxx && degree[v] == smaxx) count++;
                if(degree[v] == maxx && degree[u] == smaxx) count++;
            }
            
            return maxx + smaxx - (count >= smaxxc);
        } 
        
        for(auto& road: roads) {
            int u = road[0], v = road[1];
            if(degree[u] == maxx && degree[v] == maxx) count++;
        }
        
        return 2*maxx - (count == maxxc*(maxxc-1)/2);
    }
};

// simply cheking for every pair - O(n^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adjm(n, vector<bool>(n));
        vector<vector<int>> adjl(n);
        
        for(auto& i: roads) {
            int u = i[0], v = i[1];
            
            adjl[u].push_back(v);
            adjl[v].push_back(u);
            adjm[u][v] = 1;
            adjm[v][u] = 1;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int val = adjl[i].size();
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    int currval = val + adjl[j].size();
                    if(adjm[i][j])
                        currval--;
                    if(ans < currval)
                        ans = currval;
                }
            }
        }
        
        return ans;
    }
};
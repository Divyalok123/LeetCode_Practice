/*
https://leetcode.com/problems/count-pairs-of-nodes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// improving with two pointers - O(q * (n + E))
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int q = queries.size();
        
        vector<int> ans(q);
        int store[n], degree[n+1];
        unordered_map<int, int> um[n+1];
        
        memset(store, 0, sizeof store);
        memset(degree, 0, sizeof degree);
        
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            store[u-1]++;
            store[v-1]++;
            if(u > v)
                um[v][u]++;
            else
                um[u][v]++;
        }
        
        sort(store, store + n);
        
        for(int i = 0; i < q; i++) {
            int val = queries[i];

            int l = 0, r = n-1;
            while(l < r) {
                if(store[l] + store[r] > val)
                    ans[i]+=(r-l), r--;
                else
                    l++;
            }
            
            for(int j = 1; j <= n; j++) {
                for(const auto& [node, common]: um[j]) {
                    if(degree[j] + degree[node] > val) {
                        if(degree[j] + degree[node] - common <= val)
                            ans[i]--;
                    }
                }
            }
        }
        
        return ans;
    }
};

// binary search - O(q*(nlogn + E))
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int q = queries.size();
        
        vector<int> ans(q);
        int store[n], degree[n+1];
        unordered_map<int, int> um[n+1];
        
        memset(store, 0, sizeof store);
        memset(degree, 0, sizeof degree);
        
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            store[u-1]++;
            store[v-1]++;
            if(u > v)
                um[v][u]++;
            else
                um[u][v]++;
        }
        
        sort(store, store + n);
        
        for(int i = 0; i < q; i++) {
            int val = queries[i];

            for(int j = 1; j <= n; j++) {
                int ind = upper_bound(store, store + n, val - store[j-1]) - store;
                ans[i] += n-max(ind, j);
            }

            for(int j = 1; j <= n; j++) {
                for(const auto& [node, common]: um[j]) {
                    if(degree[j] + degree[node] > val) {
                        if(degree[j] + degree[node] - common <= val)
                            ans[i]--;
                    }
                }
            }
        }
        
        return ans;
    }
};
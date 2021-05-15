/*
https://leetcode.com/problems/graph-connectivity-with-threshold/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> parent, rank;
    
    int find(int a) {
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb) swap(pa, pb);
            
            parent[pb] = pa;
            
            if(ra == rb) rank[pa]++; 
        }
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q, 1);
        
        if(threshold == 0) return ans;
        
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i < n+1; i++) parent[i] = i;
        
        for(int i = threshold+1; i < n; i++) {
            int j = 2;
            while(i*j <= n) {
                un(i, i*j);
                j++;
            }
        }
        
        int j = 0;
        for(auto& i: queries) {
            if(find(i[0]) != find(i[1]))
                ans[j] = 0;
            
            j++;
        }
        
        return ans;
    }
};
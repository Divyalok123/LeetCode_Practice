/*
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// union-find
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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();
        
        if(c < n-1) return -1;
        
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto i: connections) 
            un(i[0], i[1]);
        
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(parent[i] == i)
                ans++;
        
        return ans-1;
    }
};
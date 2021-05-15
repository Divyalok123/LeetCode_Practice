/*
https://leetcode.com/problems/redundant-connection/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    vector<int> rank, p;
    
    int find(int a) {
        return p[a] == a ? a : p[a] = find(p[a]);
    } 
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                swap(pa, pb);
            
            p[pb] = pa;
            
            if(ra == rb)
                rank[pa]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n);
        p.resize(n);
        
        for(int i = 0; i < n; i++) p[i] = i;
        
        for(auto& i: edges) {
            if(find(i[0]-1) != find(i[1]-1))
                un(i[0]-1, i[1]-1);
            else return i;
        }
        
        return {};
    }
};
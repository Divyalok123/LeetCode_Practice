/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//union-find
class Solution {
public:
    vector<int> rank, parent;
    
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
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int maxval = INT_MIN;
        
        for(auto& i: stones)
            maxval = max({maxval, i[0], i[1]});
        
        vector<int> storer(maxval+1, -1);
        vector<int> storec(maxval+1, -1);
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(int i = 0; i < n; i++) {
            int r = stones[i][0], c = stones[i][1];
            
            if(storer[r] == -1) storer[r] = i;
            else un(i, storer[r]);
            
            if(storec[c] == -1) storec[c] = i;
            else un(i, storec[c]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++)
            if(parent[i] == i)
                count++;
        
        return n-count;
    }
};
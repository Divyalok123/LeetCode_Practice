/*
https://leetcode.com/problems/smallest-string-with-swaps/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        rank.resize(n);
        parent.resize(n);
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto& i: pairs)
            un(i[0], i[1]);
        
        vector<vector<char>> v(n);
        vector<int> ind(n);
        
        for(int i = 0; i < n; i++)
            v[find(i)].push_back(s[i]);
        
        for(int i = 0; i < n; i++)
            if(v[i].size())
                sort(v[i].begin(), v[i].end());
        
        string ans(n, '-');
        for(int i = 0; i < n; i++) {
            int p = find(i);
            
            if(ind[p] < v[p].size())
                ans[i] = v[p][ind[p]++];
        }
        
        return ans;
    }
};
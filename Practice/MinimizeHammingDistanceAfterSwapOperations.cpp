/*
https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    vector<int> rank, parent;
public:
    
    //union-find
    
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]); //path-compression
    }
    
    void uni(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1 != p2) { //union-by-rank
            if(rank[p1] > rank[p2])
                swap(p1, p2);
            
            parent[p1] = p2;
            if(rank[p1] == rank[p2])
                rank[p2]++;
        }
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        
        rank.resize(n+1, 0);
        parent.resize(n+1);
        
        for(int i = 0; i < n+1; i++)
            parent[i] = i;
        
        for(auto& i: allowedSwaps) 
            uni(i[0], i[1]);    
        
        unordered_map<int, unordered_map<int, int>> m;
        for(int i = 0; i < n; i++) 
            m[find(i)][source[i]]++;
        
        for(int i = 0; i < n; i++) {
            auto& re = m[parent[i]][target[i]]; 
            if(re > 0)
                re--;
            else ans++;
        }
        
        return ans;
    }
};
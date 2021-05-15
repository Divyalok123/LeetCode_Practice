/*
https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

//DSU
class Solution {
public:
    int find(int a, vector<int>& parent) {
        return a == parent[a] ? a : parent[a] = find(parent[a], parent);
    }
    
    bool un(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent), pb = find(b, parent);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb) swap(pa, pb);
            
            parent[pb] = pa;
            
            if(ra == rb) rank[pa]++;
            
            return 0;
        }
        
        return 1;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {    
        vector<int> alicerank, aliceparent, bobrank, bobparent;
    
        alicerank.resize(n+1);
        aliceparent.resize(n+1);
        iota(aliceparent.begin(), aliceparent.end(), 0);
        
        bobrank.resize(n+1);
        bobparent.resize(n+1);
        iota(bobparent.begin(), bobparent.end(), 0);
        
        vector<array<int, 2>> both, alice, bob;
        
        for(auto& i: edges) {
            array<int, 2> arr = {i[1], i[2]}; 
            if(i[0] == 3)
                both.push_back(arr);
            else if(i[0] == 2)
                bob.push_back(arr);
            else 
                alice.push_back(arr);
        }
        
        int ans = 0;
        int alicenodecount = 0, bobnodecount = 0;
        
        for(auto& [u, v]: both) {
            if(un(u, v, aliceparent, alicerank) == 0 && un(u, v, bobparent, bobrank) == 0)
                ans++, alicenodecount++, bobnodecount++;
        }
        
        for(auto& [u, v]: alice) {
            if(un(u, v, aliceparent, alicerank) == 0)
                ans++, alicenodecount++;
        }
        
        for(auto& [u, v]: bob) {
            if(un(u, v, bobparent, bobrank) == 0)
                ans++, bobnodecount++;
        }
         
        // cout << "ans: "  << ans << "a_node_count: " << alicenodecount << " b_node_count: " << bobnodecount << endl;
        return alicenodecount == n-1 && bobnodecount == n-1 ? edges.size()-ans : -1;
    }
};
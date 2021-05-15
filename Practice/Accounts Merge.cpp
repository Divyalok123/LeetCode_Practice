/*
https://leetcode.com/problems/accounts-merge/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n+1);
        parent.resize(n+1);
        
        for(int i = 0; i <= n; i++) 
            parent[i] = i;
        
        unordered_map<string, int> um;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                int& k = um[accounts[i][j]];
                if(k == 0)
                    k = i+1;
                else
                    un(i+1, k);
            }
        }
        
        unordered_map<int, vector<string>> umm;
        unordered_map<string, int> ummm;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(ummm[accounts[i][j]]) continue;
                umm[find(um[accounts[i][j]])].push_back(accounts[i][j]);
                ummm[accounts[i][j]] = 1;
            }
        }
        
        vector<vector<string>> ans;
        for(auto& i: umm) {
            int ind = find(um[i.second[0]]);
            ans.push_back({});
            ans[ans.size()-1].push_back(accounts[ind-1][0]);
            for(auto& j: i.second) 
                ans[ans.size()-1].push_back(j);
        }
        
        for(auto& i: ans)
            sort(i.begin()+1, i.end());
        
        return ans;
    }
};
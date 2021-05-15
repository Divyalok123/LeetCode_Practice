/*
https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

//union-find
class Solution {
public:
    
    int find(int a, vector<int>& parent)
    {
        return parent[a] == a ? a : parent[a] = find(parent[a], parent);
    }
    
    void un(int a, int b, vector<int>& rank, vector<int>& parent) {
        int pa = find(a, parent), pb = find(b, parent);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                (a ^= b), (b ^= a), (a ^= b);
            
            parent[pb] = pa;
            
            if(ra == rb)
                rank[pa]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> rank, parent;
        rank.resize(26);
        parent.resize(26);
        
        iota(parent.begin(), parent.end(), 0);
    
        for(auto& i: equations) {
            if(i[1] == '=') 
                un(i[0]-'a', i[3]-'a', rank, parent);
        }
        
        for(auto& i: equations) {
            if(i[1] == '!') 
                if(find(i[0]-'a', parent) == find(i[3]-'a', parent))
                    return 0;
        }
        
        return true;
    }
};

// simple brute force
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<bool>> yes(26, vector<bool>(26));
        vector<vector<bool>> no(26, vector<bool>(26));
        
        for(auto& i: equations) {
            
            int a = i[0]-'a';
            string eq = i.substr(1, 2);
            int b = i[3]-'a';
            
            if(eq == "==") {
                if(no[a][b] || no[b][a])
                    return false;
                
                if(a == b) continue;
                
                for(int j = 0; j < 26; j++) {
                    if(yes[a][j]) {
                        if(no[j][b] == 0)
                            yes[j][b]=1;
                        else return false;
                        yes[b][j]=1;
                    }
                }
                
                for(int j = 0; j < 26; j++) {
                    if(yes[b][j]) {
                        if(no[j][a] == 0)
                            yes[j][a]=1;
                        else return false;
                        yes[a][j]=1;
                    }
                }

                yes[a][b]=1;
                yes[b][a]=1;
                
            } else {
                if(yes[b][a] || yes[a][b])
                    return false;
                
                if(a == b) return false;
                
                for(int j = 0; j < 26; j++) {
                    if(yes[a][j]) {
                        if(yes[b][j] == 0)
                            no[b][j] = 1;
                        else return false;
                        no[j][b] = 1;
                    }
                }
                
                for(int j = 0; j < 26; j++) {
                    if(yes[b][j]) {
                        if(yes[a][j] == 0)
                            no[a][j] = 1;
                        else return false;
                        no[j][a] = 1;
                    }
                }
                    
                no[a][b]=1;
                no[b][a]=1;
            }
        }
        
        return true;
    }
};
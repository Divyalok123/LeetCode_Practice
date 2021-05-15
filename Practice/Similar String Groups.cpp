/*
https://leetcode.com/problems/similar-string-groups/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

//dfs
/* 
    method 1: make connections if they are similar and then count the number of connected components
*/

/* 
    method 2: do the same thing on the go
*/

class Solution {
public:
    
    int aresim(string& a, string& b) {
        int n = a.size();
        
        int f = -1, s = -1;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(f == -1)
                    f = i;
                else if(s == -1)
                {
                    s = i;
                    if(a[f] != b[s] || a[s] != b[f])
                        return false;
                } else
                    return false;
            }
        }
        
        return f == -1  || (f != -1 && s != -1);
    }
    
    void dfs(vector<string>& strings, string& s) {
        for(int i = 0; i < strings.size(); i++) {
            if(strings[i] == "") continue;
            
            if(aresim(s, strings[i])) {
                string news = strings[i];
                strings[i] = "";
                dfs(strings, news);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int sz = strs[0].size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(strs[i] == "") continue;
            ans++;
            string s = strs[i];
            strs[i] = "";
            dfs(strs, s);
        }
        
        return ans;
    }
};


//union-find with improved comparison (awesome improvement)
class Solution {
public:
    vector<int> rank, parent;
    
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                swap(pa, pb);
            else if(ra == rb)
                rank[pa]++;
            
            parent[pb] = pa;
        }
    } 
    
    int aresim(string& a, string& b) {
        int n = a.size();
        
        int f = -1, s = -1;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(f == -1)
                    f = i;
                else if(s == -1)
                {
                    s = i;
                    if(a[f] != b[s] || a[s] != b[f])
                        return false;
                } else
                    return false;
            }
        }
        
        return f == -1  || (f != -1 && s != -1);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int sz = strs[0].size();

        rank.resize(n);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(aresim(strs[i], strs[j]))
                    un(i, j);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(find(i) == i)
                ans++;
        
        return ans;
    }
};

//union-find
class Solution {
public:
    vector<int> rank, parent;
    
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                swap(pa, pb);
            else if(ra == rb)
                rank[pa]++;
            
            parent[pb] = pa;
        }
    } 
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int sz = strs[0].size();

        rank.resize(n);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int diff = 0;
                string& s1 = strs[i];
                string& s2 = strs[j];
                for(int k = 0; k < sz; k++) {
                    if(s1[k] != s2[k])
                        diff++;
                }
                
                if(diff == 0 || diff == 2) 
                    un(i, j);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(find(i) == i)
                ans++;
        
        return ans;
    }
};
/*
https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
*/

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

//improvement to below code
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
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
            else if (ra == rb)
                rank[pa]++;
            
            parent[pb] = pa;
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int nodes, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int j = 0;
        for(auto& i: queries)
            i.push_back(j++);
        
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        rank.resize(nodes);
        parent.resize(nodes);
        iota(parent.begin(), parent.end(), 0);
        
        int n = queries.size();
        vector<bool> ans(n);
        int k = 0, m = edgeList.size();
        j = 0;
        for(auto& i: queries) {
            int u = i[0], v = i[1], lim = i[2];
            
            while(j < m && edgeList[j][2] < lim) 
                un(edgeList[j][0], edgeList[j][1]), j++;
            
            if(find(u) == find(v)) 
                ans[i[3]] = 1; 
             
            k++;
        }
        
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
            else if (ra == rb)
                rank[pa]++;
            
            parent[pb] = pa;
        }
    }
    
    vector<bool> distanceLimitedPathsExist(int nodes, vector<vector<int>>& edgeList, vector<vector<int>>& quer) {
        vector<vector<int>> queries = quer;
        
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        rank.resize(nodes);
        parent.resize(nodes);
        iota(parent.begin(), parent.end(), 0);
        
        int n = queries.size();
        vector<bool> ans(n);
        map<vector<int>, bool> mm;
        int j = 0, k = 0, m = edgeList.size();
        for(auto& i: queries) {
            int u = i[0], v = i[1], lim = i[2];
            
            while(j < m && edgeList[j][2] < lim) 
                un(edgeList[j][0], edgeList[j][1]), j++;
            
            if(find(u) == find(v)) 
                mm[i] = 1; 
             
            k++;
        }
        
        for(int i = 0; i < n; i++)
            ans[i] = mm[quer[i]];
        
        return ans;
    }
};
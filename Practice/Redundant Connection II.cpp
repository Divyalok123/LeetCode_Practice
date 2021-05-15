#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
using namespace std;

// union-find
class Solution {
public:
    vector<int> rank, p;
    
    int find(int a) {
        return p[a] == a ? a : p[a] = find(p[a]);
    } 
    
    bool un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb)
                swap(pa, pb);
            
            p[pb] = pa;
            
            if(ra == rb)
                rank[pa]++;
            
            return 0;
        }
        
        return 1;
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1);
        p.resize(n+1);
        
        for(int i = 0; i < n; i++) p[i] = i;
        
        bool node = false;
        vector<int> cand1, cand2;
        vector<vector<int>> parent(n+1);
        for(int i = 0; i < n; i++) {
            auto& point = parent[edges[i][1]];
            point.push_back(edges[i][0]);
            if(point.size() == 2) {
                node = 1;
                cand1 = {point[0], edges[i][1]};
                cand2 = {point[1], edges[i][1]};
                break;
            }
        }
        
        for(auto& i: edges) {
            int u = i[0], v = i[1];
            if(i == cand2) continue;
            if(un(u, v)) 
            {
                if(node)
                    return cand1;
                else
                    return i;
            }
            
        }
            
        return cand2;
    }
};

// improving below dfs
class Solution {
public:
    
    void dfs(int s, int e, vector<vector<int>>& g, vector<bool>& vis, bool& check) {
        if(s==e) {
            check = 1;
            return;
        }
        
        vis[s] = 1;
        for(int& j: g[s]) {
            if(vis[j] == 0) {
                dfs(j, e, g, vis, check);
            }
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> parent(n+1);
        vector<vector<int>> v(n+1);
        for(int i = 0; i < n; i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            parent[edges[i][1]].push_back(edges[i][0]);
        }
        
        //finding two parent node
        bool node = false;
        vector<int> cand1, cand2;
        for(int i = 1; i <= n; i++)
            if(parent[i].size() == 2) {
                node = 1;
                cand1 = {parent[i][0], i};
                cand2 = {parent[i][1], i};
                break;
            }
        
        bool check = 0;
        vector<bool> vis(n+1);
        if(node == 0) { 
            for(int i = n-1; i >= 0; i--) {
                check = 0;
                vis.assign(n+1, 0);
                dfs(edges[i][1], edges[i][0], v, vis, check);

                if(check) 
                    return edges[i];
            }
        }
            
        check = 0;
        vis.assign(n+1, 0);
        dfs(cand1[1], cand1[0], v, vis, check);
        
        return check ? cand1 : cand2;
    }
};

// naive dfs, trying all edges 
class Solution {
public:
    
    void dfs(int i, vector<int>& cav, vector<vector<int>>& g, int& count, vector<bool>& vis) {
        vis[i] = 1;
        count++;
        
        for(int& j: g[i]) {
            if(vis[j] == 0 && cav != vector<int>({i, j})) {
                dfs(j, cav, g, count, vis);
            }
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        //finding root
        int root = -1;
        vector<bool> check(n+1);
        for(auto& i: edges) {
            check[i[1]] = 1;
        }
 
        for(int i = 1; i <= n; i++)
            if(check[i] == 0)
            {
                root = i;
                break;
            }
        
        if(root == -1)
            root = edges[0][0];
        
        vector<vector<int>> v(n+1);
        for(int i = 1; i <= n; i++) 
            v[edges[i-1][0]].push_back(edges[i-1][1]);
        
        vector<int> ans = {-1, -1};
        for(int i = n-1; i >= 0; i--) {
            int count = 0;
            vector<bool> vis(n+1);
            dfs(root, edges[i], v, count, vis);
        
            if(count == n) 
                return edges[i];
        }
        
        return {};
    }
};

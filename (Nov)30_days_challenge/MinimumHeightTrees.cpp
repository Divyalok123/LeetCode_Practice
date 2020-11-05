/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3519/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

/* Solution 2 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return  {0};
        vector<vector<int>> v(n);
        vector<int> degree(n);
        for(int i = 0; i < edges.size(); i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;
            degree[edges[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) 
            if(v[i].size()==1)
                q.push(i);
        
        int size, currv;
        while(n > 2) {
            size = q.size();
            n -= size;
            
            for(int i = 0; i < size; i++) {
                currv = q.front();
                q.pop();
                
                degree[currv]--;
                for(auto& node: v[currv]) {
                    degree[node]--;
                    if(degree[node] == 1)
                        q.push(node);
                }
            }
        }
        
        
        vector<int> ans;
        while(!q.empty())
            ans.push_back(q.front()), q.pop();
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    
    int lp, lc = 0; //lp -> leaf point, lc->count till leaf
    int a = -1, b = -1;
    vector<int> store; //to store the height values of every node

    void dfs(vector<vector<int>>& v, int curr, int len) {
        if(len > lc)
            lp = curr, lc = len;
        
        store[curr] = len;
        for(auto& node: v[curr])
            if(store[node] == -1)
                dfs(v, node, len+1);
    }
    
    void dfs(vector<vector<int>>& v, vector<int>& path, int curr, int len) {
        path.push_back(curr); 
        if(curr != lp && v[curr].size()==1 && len > lc) {
            int n = path.size();
            if(n&1)
                a = path[n/2], b = -1;
            else
                a = path[n/2], b = path[(n-1)/2];
            lc = len;
            path.pop_back();
            return;
        }
        
        store[curr] = len;
        for(auto& node: v[curr]) {
            if(store[node] == -1)
                dfs(v, path, node, len+1);
        }

        path.pop_back();
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        int l1;

        //building the adjacency list
        for(int i = 0; i < edges.size(); i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }

        //finding a leaf
        int sp = -1;
        for(int i = 0; i < n; i++)
            if(v[i].size()==1)
            {
                l1 = i;
                break;
            }
        
        //initiating dfs to get the farthest node(leaf) this leaf
        store.assign(n, -1);
        dfs(v, 0, 0); 
        a = lp;

        //another dfs to get the fartherst ndoe to this leaf and finding the mid node alongside
        {
            vector<int> path; //to store the path to a node
            store.assign(n, -1);
            lc = 0;
            dfs(v, path, lp, 1);
        }
        
        vector<int> ans(1, a);
        if(b != -1)
            ans.push_back(b);
        return ans;
    }
};
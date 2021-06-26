/*
https://leetcode.com/problems/flower-planting-with-no-adjacent/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//performs much better
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, -1);
        vector<vector<int>> graph(n);
        for(auto& i: paths) {
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1]-1].push_back(i[0]-1);
        }
        
        for(int i = 0; i < n; i++) {
            if(ans[i] == -1) {
                int check[5] = {0};
                for(auto& j: graph[i])
                    if(ans[j] != -1)
                        check[ans[j]] = 1;
                
                
                for(int j = 1; j <= 4; j++)
                    if(check[j] == 0)
                        ans[i] = j;
            }
        }
        
        return ans;
    }
};

//greedy
class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, -1);
        vector<vector<int>> graph(n);
        for(auto& i: paths) {
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1]-1].push_back(i[0]-1);
        }
        
        for(int i = 0; i < n; i++) {
            if(ans[i] == -1) {
                unordered_set<int> s({1, 2, 3, 4});
                for(auto& j: graph[i])
                    if(ans[j] != -1)
                        s.erase(ans[j]);
                
                ans[i] = *(s.begin());
            }
        }
        
        return ans;
    }
};

//dfs
class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int i, vector<int>& ans) {
        if(ans[i] == -1) {
            unordered_set<int> s({1, 2, 3, 4});
            
            for(auto& j: graph[i])
                if(ans[j] != -1)
                    s.erase(ans[j]);
            
            ans[i] = *(s.begin());
            
            for(auto& j: graph[i])
                if(ans[j] == -1)
                    dfs(graph, j, ans);
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n, -1);
        vector<vector<int>> graph(n);
        for(auto& i: paths) {
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1]-1].push_back(i[0]-1);
        }
        
        for(int i = 0; i < n; i++) {
            if(ans[i] == -1) {
                dfs(graph, i, ans);
            }
        }
        
        return ans;
    }
};
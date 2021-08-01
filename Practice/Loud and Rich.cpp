/*
https://leetcode.com/problems/loud-and-rich/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dfs
static int fio = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    void dfs(int i, vector<vector<int>>& graph, vector<int>& minvalues, vector<int>& quiet) {
        if(minvalues[i] != INT_MAX) return;
        
        int minvalue = quiet[i];
        int minvalueNode = i;
        
        for(auto& nex: graph[i]) {
            dfs(nex, graph, minvalues, quiet);
            if(quiet[minvalues[nex]] < minvalue) {
                minvalue = quiet[minvalues[nex]];
                minvalueNode = minvalues[nex];
            }
        }
        
        minvalues[i] = minvalueNode;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        int m = richer.size();
        
        vector<vector<int>> graph(n);
        for(auto& i: richer)
            graph[i[1]].push_back(i[0]);
        
        vector<int> minvalues(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            if(minvalues[i] == INT_MAX) {
                dfs(i, graph, minvalues, quiet);
            }
        }
        
        return minvalues;
    }
};
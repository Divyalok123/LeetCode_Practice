/*
https://leetcode.com/problems/shortest-path-with-alternating-colors/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> red(n), blue(n);
        
        for(auto& i: red_edges)
            red[i[0]].push_back(i[1]);
        vector<int> redvis(n);
        
        for(auto& i: blue_edges)
            blue[i[0]].push_back(i[1]);
        vector<int> bluevis(n);
        
        vector<int> ans(n, -1);
        using arr = array<int, 2>;
        queue<arr> q;
        q.push({0, 0});
        q.push({0, 1});
        int val = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto [node, path] = q.front();
                q.pop();
                
                // cout << node << " " << path << endl;
                if(ans[node] == -1 || ans[node] > val)
                    ans[node] = val;
                
                if(path== 0)
                    bluevis[node] = 1;
                else 
                    redvis[node] = 1;
                auto& ref = path == 0 ? blue : red;
                for(int nex: ref[node]) {
                    if((path == 0 && !redvis[nex]) || (path == 1 && !bluevis[nex]))
                        q.push({nex, 1-path});
                }
            }
            val++;
        }
        
        return ans;
    }
};
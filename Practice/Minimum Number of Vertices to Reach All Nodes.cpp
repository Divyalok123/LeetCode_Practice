/*
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        
        for(auto& e: edges) {
            int u = e[0], v = e[1];
            degree[v]++;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(degree[i] == 0) 
                ans.push_back(i);
        
        return ans;
    }
};
/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.Add Binary
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        vector<int> nodes(n, 0);
        for(int i = 0; i < p.size(); i++) {
            v[p[i][1]].push_back(p[i][0]);
            nodes[p[i][0]]++;
        }
        
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(nodes[i] == 0)
                q.push(i);
        
        
        vector<int> ans;
        while(!q.empty()) {
            int topel = q.front();
            q.pop();
            
            ans.push_back(topel);
            for(auto a: v[topel]) {
                nodes[a]--;
                if(nodes[a] == 0)
                    q.push(a);
            }
        }
        if(ans.size() != n) return {}; 
        return ans;
    }
};
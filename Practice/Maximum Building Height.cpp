/*
https://leetcode.com/problems/maximum-building-height/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if(r.back().front() != n)
            r.push_back({n, n-1});

        int sz = r.size();
        for(int i = 1; i < sz; i++) 
            r[i][1] = min(r[i][1], r[i-1][1] + (r[i][0]-r[i-1][0]));
        
        for(int i = sz-2; i >= 0; i--)
            r[i][1] = min(r[i][1], r[i+1][1] + (r[i+1][0]-r[i][0]));
        
        int ans = 0;
        for(int i = 0; i < sz-1; i++) {
            int left = r[i][0], leftval = r[i][1];
            int right = r[i+1][0], rightval = r[i+1][1];
            ans = max(ans, (leftval + rightval + right-left)/2);
        }
        
        return ans;
    }
};
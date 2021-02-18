/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3641/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> v(n);
        
        for(int i = 0; i < n; i++) {
            auto itr = lower_bound(mat[i].rbegin(), mat[i].rend(), 1);
            int val = mat[i].rend()-itr;
            v[i] = {val, i};
        }
        
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = v[i].second;
        return ans;
    }
};

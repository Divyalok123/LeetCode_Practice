/*
https://leetcode.com/problems/most-profit-assigning-work/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n = diff.size();
        vector<pair<int, int>> v(n);
        
        for(int i = 0; i < n; i++)
            v[i] = {diff[i], profit[i]};
        
        sort(v.begin(), v.end());
        
        int maxv = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(v[i].second > maxv)
                maxv = v[i].second;
            v[i].second = maxv;
        }
        
        int ans = 0;
        for(int& i: worker) {
            auto itr = upper_bound(v.begin(), v.end(), make_pair(i, numeric_limits<int>::max()));
            if(itr != v.begin()) {
                itr = prev(itr);
                ans += itr->second;
            }
        }
        
        return ans;
    }
};
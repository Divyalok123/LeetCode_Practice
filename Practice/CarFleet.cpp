/*
https://leetcode.com/problems/car-fleet/
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) 
            v[i] = make_pair(pos[i], speed[i]);
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        double maxv = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            double val = ((double)target-v[i].first)/v[i].second;
            if(val > maxv) {
                maxv = val;
                ans++;
            }
        }
        
        return ans;
    }
};
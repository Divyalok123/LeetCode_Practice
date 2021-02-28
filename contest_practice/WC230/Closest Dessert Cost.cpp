#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& v, int ind, int val, int& ans, int& finalans, int target,vector<int>& q) {
        if(ind == v.size()) {
            int newval = abs((long long)target-val); 
            
            if(newval < ans) {
                ans = newval;
                finalans = val;
            }
            
            return;
        }

        dfs(v, ind+1, val, ans, finalans, target, q);
        if(q[ind] <= 1) 
            dfs(v, ind+1, val + v[ind], ans, finalans, target, q);
        
        if(q[ind] == 0)
            dfs(v, ind+1, val + 2*v[ind], ans, finalans, target, q);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX, finalans = INT_MAX; 
        int n = baseCosts.size(), m = toppingCosts.size();
        for(int i = 0; i < n; i++) {
            vector<int> q(m, 0);
            dfs(toppingCosts, 0, baseCosts[i], ans, finalans, target, q);
        }
        
        return finalans;
    }
};
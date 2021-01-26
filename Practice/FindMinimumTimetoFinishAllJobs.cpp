/*
https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& v, vector<int>& jobs, int& ans, int i, int lim, int mv) {
        if(i == jobs.size()) {
            if(mv < ans) ans = mv;
            return;
        }
        
        unordered_set<int> s;
        for(int j = 0; j < v.size(); j++) {
            int val = jobs[i] + v[j];
            if(s.find(val) != s.end() || val > lim) continue;
            v[j] += jobs[i];
            dfs(v, jobs, ans, i+1, lim, max(mv, v[j]));
            v[j] -= jobs[i];
            s.insert(val);
        }
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        if(k == n) return *max_element(jobs.begin(), jobs.end());
        
        vector<int> v(k);
        sort(jobs.rbegin(), jobs.rend());
            
        int lim = 0;
        for(int i = 0; i < n; i += k)
            lim += jobs[i];
        
        int ans = lim;
        dfs(v, jobs, ans, 0, lim, 0);
        
        return ans;
    }
};
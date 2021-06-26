/*
https://leetcode.com/problems/subsets-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// iterative
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(1);
        int sz = 1, n = nums.size();
        for(int i = 0; i < n; i++) {
            int st = i >= 1 && nums[i] == nums[i-1] ? sz : 0;
            sz = ans.size();
            
            for(int j = st; j < sz; j++) {
                vector<int> v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};

// another way to dfs
class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<int>& vec, vector<vector<int>>& ans) {
        ans.push_back(vec);
        
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            vec.push_back(nums[j]);
            dfs(nums, j+1, vec, ans);
            vec.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0, vec, ans);
        return ans;
    }
};

// simple dfs
class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<int>& vec, vector<vector<int>>& ans, bool choosen) {
        if(i == nums.size()) {
            ans.push_back(vec);
            return;
        }
        
        dfs(nums, i+1, vec, ans, 0);
        if(i > 0 && nums[i] == nums[i-1] && !choosen) return;
        vec.push_back(nums[i]);
        dfs(nums, i+1, vec, ans, 1);
        vec.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0, vec, ans, 0);
        return ans;
    }
};
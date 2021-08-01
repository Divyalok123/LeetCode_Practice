/*
https://leetcode.com/problems/predict-the-winner/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// diff recursion with memo - O(n^2)
class Solution {
public:
    int cache[21][21];
    
    int dfs(vector<int>& nums, int i, int j) {
        if(i > j) return 0;
        
        int& ans = cache[i][j];
        if(ans != -1)
            return ans;
        
        int left = nums[i] + min(dfs(nums, i+2, j), dfs(nums, i+1, j-1));
        int right = nums[j] + min(dfs(nums, i, j-2), dfs(nums, i+1, j-1));
        
        return ans = max(left, right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0) return 1;
        fill_n(*cache, sizeof cache/sizeof **cache, -1);
        int total = 0;
        for(int& i: nums) total += i;
        int val = dfs(nums, 0, n-1);
        return total - 2*val <= 0; 
    }
};

// naive recursion - O(2^n)
class Solution {
public:
    
    bool dfs(vector<int>& nums, int i, int j, int p1, int p2, int t) {
        if(i > j)
            return p1 >= p2 ? 0 : 1;
        
        int left, right;
        if(t == 0) {
            left = dfs(nums, i+1, j, p1 + nums[i], p2, !t);
            right = dfs(nums, i, j-1, p1 + nums[j], p2, !t);
        } else {
            left = dfs(nums, i+1, j, p1, p2 + nums[i], !t);
            right = dfs(nums, i, j-1, p1, p2 + nums[j], !t);
        }
        
        if(left == t || right == t) return t;
        return !t;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return !dfs(nums, 0, n-1, 0, 0, 0);
    }
};
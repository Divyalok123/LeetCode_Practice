/*
https://leetcode.com/problems/closest-subsequence-sum/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// replacing binary search with two pointers
class Solution {
public:
    
    int abss(int v) {
        return v < 0 ? -v : v;
    }
    
    int ind;
    void genSubset(vector<int>& nums, int i, int j, int sum, vector<int>& store) {
        if(i == j + 1)
        {
            store[ind++] = sum;
            return;
        }
        
        genSubset(nums, i + 1, j, sum + nums[i], store);
        genSubset(nums, i + 1, j, sum, store);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        vector<int> left(1 << (n/2));
        vector<int> right(1 << ((n+1)/2));
        
        ind = 0;
        genSubset(nums, 0, n/2 - 1, 0, left);
        ind = 0;
        genSubset(nums, n/2, n-1, 0, right);
        
        sort(right.begin(), right.end());
        sort(left.begin(), left.end());
        
        left.erase(unique(left.begin(), left.end()), left.end());
        right.erase(unique(right.begin(), right.end()), right.end());

        int ans = abss(goal);
        int n1 = left.size(), n2 = right.size();
        int i = 0, j = n2-1;
        
        while(i < n1 && j >= 0) {
            int val = left[i] + right[j];
            if(val < goal) i++;
            else if(val > goal) j--;
            else return 0;
            
            ans = min(ans, abss(val-goal));
        }
        
        return ans;
    }
};

// 1*binary search
class Solution {
public:
    
    int abss(int v) {
        return v < 0 ? -v : v;
    }
    
    int ind;
    void genSubset(vector<int>& nums, int i, int j, int sum, vector<int>& store) {
        if(i == j + 1)
        {
            store[ind++] = sum;
            return;
        }
        
        genSubset(nums, i + 1, j, sum + nums[i], store);
        genSubset(nums, i + 1, j, sum, store);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        vector<int> left(1 << (n/2));
        vector<int> right(1 << ((n+1)/2));
        
        ind = 0;
        genSubset(nums, 0, n/2 - 1, 0, left);
        ind = 0;
        genSubset(nums, n/2, n-1, 0, right);
        
        sort(right.begin(), right.end());
        right.erase(unique(right.begin(), right.end()), right.end());
        
        int ans = abss(goal);
        int n1 = left.size();
        
        for(int i = 0; i < n1; i++) {
            int val = goal-left[i];
            auto itr = upper_bound(right.begin(), right.end(), val);
            
            if(itr != right.end())
                ans = min(ans, abss(val - *itr));
            
            if(itr != right.begin())
                ans = min(ans, abss(val - *prev(itr)));
        }
        
        return ans;
    }
};

// generate all subsets + 2*binary Search - O(2^(n/2)log(2^(n/2)))
class Solution {
public:
    
    int abss(int v) {
        return v < 0 ? -v : v;
    }
    
    int ind;
    void genSubset(vector<int>& nums, int i, int j, int sum, vector<int>& store) {
        if(i == j + 1)
        {
            store[ind++] = sum;
            return;
        }
        
        genSubset(nums, i + 1, j, sum + nums[i], store);
        genSubset(nums, i + 1, j, sum, store);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        vector<int> left(1 << (n/2));
        vector<int> right(1 << ((n+1)/2));
        
        ind = 0;
        genSubset(nums, 0, n/2 - 1, 0, left);
        ind = 0;
        genSubset(nums, n/2, n-1, 0, right);
        
        sort(right.begin(), right.end());
        
        int ans = abss(goal);
        int n1 = left.size();
        
        for(int i = 0; i < n1; i++) {
            int val1 = left[i]-goal, val2 = goal-left[i];
            auto itr = upper_bound(right.begin(), right.end(), val1);
            auto itr2 = upper_bound(right.begin(), right.end(), val2);
            
            if(itr != right.end())
                ans = min(ans, abss(val1 + *itr));
            
            if(itr != right.begin())
                ans = min(ans, abss(val1 + *prev(itr)));
            
            if(itr2 != right.end())
                ans = min(ans, abss(val2 - *itr2));
            
            if(itr2 != right.begin())
                ans = min(ans, abss(val2 - *prev(itr2)));
        }
        
        return ans;
    }
};
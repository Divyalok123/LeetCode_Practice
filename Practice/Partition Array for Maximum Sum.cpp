/*
https://leetcode.com/problems/partition-array-for-maximum-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bottom-up dp
class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 1) return arr[0];
        
        int dp[n];
        memset(dp, 0, n*sizeof(int));
        
        int maxx = 0;
        for(int i = 0; i < n; i++) {
            if(i <= k-1) {
                maxx = max(maxx, arr[i]);
                dp[i] = (i+1)*maxx;
            } else {
                int maxval = 0;
                for(int j = i; j > i-k; j--) {
                    maxval = max(maxval, arr[j]);
                    dp[i] = max(dp[i], (i-j+1)*maxval + dp[j-1]);
                }
            }
        }
        
        return dp[n-1];
    }
};


// top-down dp
class Solution {
public:
    vector<int> cache;
    int helper(vector<int>& arr, int k, int i) {
        if(i >= arr.size())
            return 0;
        
        int& ans = cache[i];
        if(ans != -1)
            return ans;
        
        int maxval = 0;
        int lim = i + k <= arr.size() ? i + k : arr.size();
        for(int j = i; j < lim; j++) {
            maxval = max(maxval, arr[j]);
            ans = max(ans, maxval*(j-i+1) + helper(arr, k, j+1));
        }
        
        return ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 1) return arr[0];
        cache.assign(n, -1);
        return helper(arr, k, 0);
    }
};

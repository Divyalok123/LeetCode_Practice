/*
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// Improvement (Single Pass after presum)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& pre, int k) {
        int n = pre.size();
        if(n*1.0/k == 3)
            return {0, k, 2*k};
        
        for(int i = 1; i < n; i++)
            pre[i] += pre[i-1];
        
        for(int i = n-1; i >= k; i--) 
            pre[i] -= pre[i-k];
        
        array<int, 2> one = {0, 0};
        array<int, 3> two = {0, 0, 0};
        array<int, 4> three = {0, 0, 0, 0};
        
        for(int i = 3*k-1; i < n; i++) {
            int val1 = pre[i-2*k];            
            if(one[0] < val1)
                one = {val1, i-3*k+1};

            int val2 = pre[i-k] + one[0];
            if(two[0] < val2)
                two = {val2, one[1], i-2*k+1};

            int val3 = pre[i] + two[0];
            if(three[0] < val3)
                three = {val3, two[1], two[2], i-k+1};
        }
        
        return {three[1], three[2], three[3]};
    }
};

// Prefix-Suffix : O(n)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& pre, int k) {
        int n = pre.size();
        if(n*1.0/k == 3)
            return {0, k, 2*k};
        
        for(int i = 1; i < n; i++)
            pre[i] += pre[i-1];
        
        vector<array<int, 2>> left(n), right(n);
        vector<int> ans(4, 0);
        
        left[k-1] = {pre[k-1], 0};
        for(int i = k; i < n; i++) {
            int val = pre[i]-pre[i-k];
            array<int, 2> newans = {val, i-k+1};
            left[i] = (val > left[i-1][0] ? newans : left[i-1]);
        }
        
        right[n-k] = {pre[n-1]-pre[n-k-1], n-k};
        for(int i = n-k-1; i > 0; i--) {
            int val = pre[i+k-1]-pre[i-1];
            array<int, 2> newans = {val, i};
            right[i] = (val >= right[i+1][0] ? newans : right[i+1]);
        }
        
        for(int i = 2*k-1; i < n-k; i++) {
            int val = pre[i]-pre[i-k] + left[i-k][0] + right[i+1][0];
            if(val > ans[0]) {
                ans = {val, left[i-k][1], i-k+1, right[i+1][1]};
            }
        }
        
        return {ans[1], ans[2], ans[3]};
    }
};
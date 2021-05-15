/*
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Better O(n) space implementation
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& pre, int l, int m) {
        int n = pre.size();
        if(n == l + m) {
            int sum = 0;
            for(int& i: pre) sum += i;
            return sum;
        }
        
        for(int i = 1; i < n; i++) 
            pre[i] += pre[i-1];

        int ans = pre[l+m-1], lmax = pre[l-1], mmax = pre[m-1];
        for(int i = l+m; i < n; i++) {
            int newl = pre[i-m]-pre[i-l-m];
            int newm = pre[i-l]-pre[i-l-m];
            
            if(newl > lmax) lmax = newl;
            if(newm > mmax) mmax = newm;
            
            ans = max(ans, max(lmax + pre[i]-pre[i-m], mmax + pre[i]-pre[i-l]));
        }
        
        return ans;
    }
};

//prefix-sufix sum - naive implementation - Time: O(n), Space: O(n);
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int l, int m) {
        int n = A.size();
        if(n == l + m) {
            int sum = 0;
            for(int& i: A) sum += i;
            return sum;
        }
        
        vector<int> pre(n);
        pre[0] = A[0];
        for(int i = 1; i < n; i++) 
            pre[i] += pre[i-1];

        if(l > m)
            swap(l, m);
        
        vector<int> prel(n), sufl(n), prem(n), sufm(n);
        for(int i = l-1; i < n-l; i++)
        {
            prel[i] = max((i > 0 ? prel[i-1] : 0), pre[i]-(i-l >= 0 ? pre[i-l] : 0));
            if(i >= m-1)
                prem[i] = max((i > 0 ? prem[i-1] : 0), pre[i]-(i-m >= 0 ? pre[i-m] : 0));
        }
        
        for(int i = n-l; i >= 0; i--) {
            sufl[i] = max((i < n-1 ? sufl[i+1] : 0), pre[i+l-1]-(i > 0 ? pre[i-1] : 0));
            if(i+m-1 < n)
                sufm[i] = max((i < n-1 ? sufm[i+1] : 0), pre[i+m-1]-(i > 0 ? pre[i-1] : 0));
        }
        
        int ans = 0;
        for(int i = l-1; i < n-l; i++) {
            if(i < n-m)
                ans = max(ans, prel[i] + sufm[i+1]);
            if(i >= m-1)
                ans = max(ans, prem[i] + sufl[i+1]);
        }
        
        return ans;
    }
};
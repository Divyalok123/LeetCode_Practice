/*
https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Applying Sliding Window - O(m*n)
class Solution {
public:

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1));
        int ans = 0;
        int k = 1;
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++) {
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i-1][j-1];
                
                if(k <= i && k <= j && pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k] <= threshold)
                    ans = k++;
                
            }
        
        return ans;
    }
};

// Prefix Sum with binary search - O(n*m*log(min(n, m)))
class Solution {
public:
    bool check(vector<vector<int>>& pre, int k, int threshold) {
        int n = pre.size()-1, m = pre[0].size()-1;
        for(int i = 0; i <= n-k; i++) {
            for(int j = 0; j <= m-k; j++) {
                if(pre[i+k][j+k] - pre[i+k][j] - pre[i][j+k] + pre[i][j] <= threshold)
                    return 1;    
            }
        }
        return 0;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1));
        int ans = 0;
        
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++) 
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i-1][j-1];
        
        int kmax = min(n, m);
        int l = 1, r = kmax;
        while(l <= r) {
            int k = (l + r)/2;
            
            if(check(pre, k, threshold)) {
                l = k+1;
                ans = k;
            } else
                r = k-1;
        }
        
        return ans;
    }
};

// Naive Prefix Sum - O(n*m*min(n, m))
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1));
        int ans = 0;
        
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++) 
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i-1][j-1];
        
        int kmax = min(n, m);
        for(int k = kmax; k >= 1; k--) {
            for(int i = 0; i <= n-k; i++) {
                for(int j = 0; j <= m-k; j++) {
                    if(pre[i+k][j+k] - pre[i+k][j] - pre[i][j+k] + pre[i][j] <= threshold)
                        return k;    
                }
            }
        }
        
        return ans;
    }
};
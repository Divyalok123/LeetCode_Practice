/*
https://leetcode.com/problems/count-submatrices-with-all-ones/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        vector<vector<int>> h(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j]) {
                    h[i][j] = i > 0 ? h[i-1][j]+1 : 1;
                    ans += h[i][j];
                    int val = h[i][j];                    
                    int k = j-1;
                    while(k >= 0) {
                        ans += val = min(h[i][k], val);
                        k--;
                    }
                    
                }
                else h[i][j] = 0;
            }
            
        }
        
        return ans;
    }
};

/* Solution 1 (using largest rectangle in histogram problem) */
class Solution {
public:
    int hist(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        
        vector<int> dp(n);
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(s.size() && v[s.top()] >= v[i]) s.pop();
            
            if(s.size()) {
                int ind = s.top();
                dp[i] += dp[ind] + v[i]*(i-ind);
            } else 
                dp[i] = v[i] * (i+1);
            
            s.push(i);
        }
        
        for(int& i: dp) ans += i;
        return ans;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        vector<int> h(m);
        for(int j = 0; j < m; j++)
            if(mat[0][j]) h[j] = 1;
        
        ans += hist(h);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j]) h[j]++;
                else h[j] = 0;
            }
            
            ans += hist(h);
        }
        
        return ans;
    }
};
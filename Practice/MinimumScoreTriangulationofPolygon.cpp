/*
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 (dp)
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        if(n <= 2) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i <= n-len; i++) {
                int last = i + len-1;
                for(int j = i+1; j < last; j++) {
                    int v = dp[i][j-i+1] + A[i]*A[j]*A[last] + dp[j][last-j+1];
                    if(dp[i][len] == 0) dp[i][len] = v;
                    else if(v < dp[i][len]) dp[i][len] = v;
                }
            }
        }             
        return dp[0][n];
    }
};

// Solution 1 (memo)
class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& A, int i = 0, int j = -1) {
        int n = A.size();
        if(n <= 2) return 0;
        if(j == -1) {
            j = n-1;
            dp.resize(n, vector<int>(n, -1));
        }
        
        if(i >= j-1) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
            int a = minScoreTriangulation(A, i, k) + A[i]*A[k]*A[j] + minScoreTriangulation(A, k, j);
            if(a > 0 && ans > a) ans = a; 
        }
        
        return dp[i][j] = ans;
    }
};
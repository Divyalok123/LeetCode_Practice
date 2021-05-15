/*
https://leetcode.com/problems/knight-dialer/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Awesome O(log(n)) time solution
// taking the neighbors and the points as edges of a graph we can make an adjacency matrix (A) representing the graph. 
// Now, the thing we should know is that the ij'th entry of A^k will give us the number of k-length walks connecting
// the vertices i and j.

class Solution {
public:
    int MOD;
    
    void multiply(int mat1[][10], int mat2[][10]) {
        int ans[10][10];
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                ans[i][j] = 0;
                for(int k = 0; k < 10; k++) 
                    ans[i][j] = (ans[i][j] + mat1[i][k]*1ll*mat2[k][j])%MOD;
            }
        }
        
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                mat1[i][j] = ans[i][j];
    }
    
    void matPower(int res[][10], int mat[][10], int p) {
        if(p == 1)
            return;
        
        matPower(res, mat, p/2);
        multiply(res, res);
        
        if(p&1) 
            multiply(res, mat);
    }
    
    int knightDialer(int n) {
        MOD = 1000000007;
        if(n == 1) return 10;
        
        vector<vector<int>> pj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        
        int mat[10][10];
        memset(mat, 0, 400);
        
        for(int i = 0; i < 10; i++) 
            for(int& j: pj[i])
                mat[i][j] = 1;
        
        int copy[10][10];
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                copy[i][j] = mat[i][j];
        
        matPower(mat, copy, n-1);
        
        long long ans = 0;
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                ans = (ans + mat[i][j])%MOD;
        
        return ans;
    }
};

// Improved bottom-up: O(1) space & O(N) time
class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1000000007;
        int dp[10];
        for(int i = 0; i < 10; i++)
            dp[i] = 1;

        vector<vector<int>> pj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        long long ans = 0;
        for(int i = 1; i < n; i++) {
            int newdp[10] = {0};
            for(int j = 0; j < 10; j++)
                for(int& k: pj[j])
                    newdp[j] = (newdp[j]*1ll + dp[k])%MOD;
            for(int j = 0; j < 10; j++)
                dp[j] = newdp[j];
        }
        
        for(int i = 0; i < 10; i++)
            ans = (ans + dp[i])%MOD;
        
        return ans;
    }
};

// bottom-up dp: O(N) space & time
class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1000000007;
        int dp[n][10];
        memset(dp, 0, n*40);
        for(int i = 0; i < 10; i++)
            dp[0][i] = 1;

        vector<vector<int>> pj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        long long ans = 0;
        for(int i = 1; i < n; i++)
            for(int j = 0; j < 10; j++)
                for(int& k: pj[j])
                    dp[i][j] = (dp[i][j]*1ll + dp[i-1][k])%MOD;
            
        for(int i = 0; i < 10; i++)
            ans = (ans + dp[n-1][i])%MOD;
        
        return ans;
    }
};

// top-down dp: O(N) space & time
class Solution {
public:
    int MOD;
    vector<vector<int>> cache;
    int solve(int jumps, int i, vector<vector<int>>& possiblejumps) {
        if(jumps == 0)
            return 1;
        
        if(cache[i][jumps])
            return cache[i][jumps];
        
        long long ans = 0;
        for(int& j: possiblejumps[i]) 
            ans = (ans + solve(jumps-1, j, possiblejumps))%MOD;
        
        return cache[i][jumps] = ans;
    }
    
    int knightDialer(int n) {
        MOD = 1000000007;
        cache.resize(10, vector<int>(n));
        vector<vector<int>> possiblejumps;
        possiblejumps = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        
        long long ans = 0;
        for(int i = 0; i < 10; i++)
            ans = (ans + solve(n-1, i, possiblejumps))%MOD;
    
        return ans;
    }
};
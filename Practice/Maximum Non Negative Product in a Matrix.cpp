/*
https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// bottom-up dp
class Solution {
public:
    #define MOD 1000000007
    #define MIN LLONG_MIN
    #define MAX LLONG_MAX
    #define ll long long
    #define all2 array<ll, 2>
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<all2>> dp(n, vector<all2>(m));
        
        dp[0][0] = all2{(ll)grid[0][0], (ll)grid[0][0]};
        
        for(int i = 1; i < m; i++)
            dp[0][i] = all2{(ll)grid[0][i] * dp[0][i-1][0], (ll)grid[0][i] * dp[0][i-1][1]};
        
        for(int i = 1; i < n; i++)
            dp[i][0] = all2{(ll)grid[i][0] * dp[i-1][0][0], (ll)grid[i][0] * dp[i-1][0][1]};
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                all2 top = dp[i-1][j];
                all2 left = dp[i][j-1];
                
                ll minval = MAX, maxval = MIN;
                
                if(top[0] < minval) minval = top[0];
                if(left[0] < minval) minval = left[0];
                
                if(top[1] > maxval) maxval = top[1];
                if(left[1] > maxval) maxval = left[1];
                
                minval *= (ll)grid[i][j];
                maxval *= (ll)grid[i][j];
                
                dp[i][j] = grid[i][j] >= 0 ? all2{minval, maxval} : all2{maxval, minval};
            }
        }
        
        return dp[n-1][m-1][1] < 0 ? -1 : dp[n-1][m-1][1] % MOD;
    }
};

// top-down dp
class Solution {
public:
    #define MOD 1000000007
    #define MIN LLONG_MIN
    #define MAX LLONG_MAX
    #define ll long long
    #define mp make_pair

    vector<vector<array<ll, 2>>> cache;
    array<ll, 2> defaultt;
    
    array<ll, 2> dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if(i == n-1 && j == m-1)
            return {grid[i][j], grid[i][j]};
        
        if(cache[i][j] != defaultt)
            return cache[i][j];
        
        ll minval = MAX, maxval = MIN;
        
        if(i < n-1) {
            auto a = dfs(i+1, j, grid, n, m);
            if(a[0] < minval) minval = a[0];
            if(a[1] > maxval) maxval = a[1];
        }
        
        if(j < m-1) {
            auto b = dfs(i, j+1, grid, n, m);
            if(b[0] < minval) minval = b[0];
            if(b[1]> maxval) maxval = b[1];
        }
        
        minval *= grid[i][j];
        maxval *= grid[i][j];
        
        array<ll, 2> ans;
        if(grid[i][j] >= 0) ans = {minval, maxval};
        else ans = {maxval, minval};
        
        return cache[i][j] = ans;
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        defaultt = {MIN, MIN};
        
        cache.resize(n, vector<array<ll, 2>>(m, defaultt));
        auto ans = dfs(0, 0, grid, n, m);
        return ans[1] < 0 ? -1 : ans[1] % MOD;
    }
};
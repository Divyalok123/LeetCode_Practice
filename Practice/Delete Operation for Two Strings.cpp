/*
https://leetcode.com/problems/delete-operation-for-two-strings/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bottom-up dp (longest common sub)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 0; i <= m; i++) dp[0][i] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
        
        return n + m - 2*dp[n][m];
    }
};

// top-down dp (no. of deletions)
class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string& word1, string& word2, int n, int m, int i, int j) {
        if(i == n || j == m)
            return i == n ? m-j : n-i;
        
        int& ans = dp[i][j];
        if(ans != -1)
            return ans;
        
        if(word1[i] == word2[j])
            return ans = solve(word1, word2, n, m, i+1, j+1);
        
        return ans = 1 + min(solve(word1, word2, n, m, i+1, j), solve(word1, word2, n, m, i, j+1));        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        dp.resize(n, vector<int>(m, -1));
        return solve(word1, word2, n, m, 0, 0);        
    }
};
/*
https://leetcode.com/problems/interleaving-string/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// bottom-up dp
class Solution {
public:
    
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        int n3 = s3.size(), n1 = s1.size(), n2 = s2.size();
        
        if(n3 != n1 + n2) return false;

        int dp[101][101];
        memset(dp, 0, sizeof dp);
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n1; i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        
        for(int j = 1; j <= n2; j++)
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++) {
                if(s2[j-1] == s3[i+j-1])
                    dp[i][j] |= dp[i][j-1];
                if(s1[i-1] == s3[i+j-1])
                    dp[i][j] |= dp[i-1][j];
            }
        
        return dp[n1][n2];
    }
};

// top-down dfs + memo
class Solution {
public:
    
    int cache[101][101];
    bool dfs(int i, int j, int k, const string& s1, const string& s2, const string& s3) {
        if(k == s3.size()) return true;
        
        if(i == s1.size())
            return s2.substr(j) == s3.substr(k);
        if(j == s2.size())
            return s1.substr(i) == s3.substr(k);
        
        int& ans = cache[i][j];
        if(ans != -1)
            return ans;
        
        ans = false;
        if(s3[k] == s1[i]) 
            ans |= dfs(i+1, j, k+1, s1, s2, s3);
        
        if(s3[k] == s2[j])
            ans |= dfs(i, j+1, k+1, s1, s2, s3);
        
        return ans;
    }
    
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        int n3 = s3.size(), n1 = s1.size(), n2 = s2.size();
        
        if(n3 != n1 + n2) return false;
        fill_n(*cache, sizeof cache/sizeof **cache, -1);
        
        return dfs(0, 0, 0, s1, s2, s3);
    }
};
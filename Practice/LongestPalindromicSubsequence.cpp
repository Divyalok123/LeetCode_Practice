/*
https://leetcode.com/problems/longest-palindromic-subsequence/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n <= 1) return n;
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if(i < n-1) 
                dp[i][i+1] = 1 + (s[i] == s[i+1]);
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+2; j < n; j++) {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else 
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        // cout << "DP" << endl;
        // for(auto& v: dp) {
        //     for(int& i: v)
        //         cout << i << " ";
        //     cout << endl;
        // }
        
        return dp[0][n-1];
    }
};
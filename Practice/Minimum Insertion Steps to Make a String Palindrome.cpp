/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// improving space
class Solution {
public:
    
    int minInsertions(string s) {
        int ans = 0, n = s.size();
        if(n == 1) return ans;

        int dp[500][2];

        for(int i = 0; i < n-1; i++) {
            dp[i][1] = s[i] != s[i+1];
            dp[i][0] = 0;
        }
        
        dp[n-1][0] = 0;
        
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j <= n-i; j++) {
                int r = j+i-1;
                int prev = dp[j+1][0];
                int prev2 = dp[j][1], prev3 = dp[j+1][1];
                dp[j][1] = (s[j] == s[r]) ? prev : min(prev2, prev3) + 1;
                dp[j][0] = prev2;
            }
        }
        
        return dp[0][1];        
    }
};

// bottom-up dp
class Solution {
public:
    
    int minInsertions(string s) {
        int ans = 0, n = s.size();
        if(n == 1) return ans;

        int dp[500][500];

        for(int i = 0; i < n; i++) 
            dp[i][i] = 0;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= n-i; j++) {
                if(s[j] == s[j+i-1])
                    dp[j][j+i-1] = j+1 <= j+i-2 ? dp[j+1][j+i-2] : 0;
                else
                    dp[j][j+i-1] = 1 + min(dp[j+1][j+i-1], dp[j][j+i-2]);
            }
        }
        
        return dp[0][n-1];        
    }
};

// top-down dp
class Solution {
public:
    int cache[500][500];
    int helper(string& s, int i, int j) {
        if(i >= j) return 0;
        
        int& ans = cache[i][j];
        if(ans != -1)
            return ans;
        
        if(s[i] == s[j])
            return ans = helper(s, i+1, j-1);
        
        int a = helper(s, i+1, j);
        int b = helper(s, i, j-1);
        
        return ans = 1 + (a < b ? a : b);
    }
    
    int minInsertions(string s) {
        int ans = 0, n = s.size();
        if(n == 1) return ans;
            
        memset(cache, -1, sizeof(cache));
        return helper(s, 0, n-1);        
    }
};
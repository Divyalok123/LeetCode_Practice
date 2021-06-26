/*
https://leetcode.com/problems/palindromic-substrings/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

// improving space - O(1) space & O(n^2) time
class Solution {
public:
    
    void gosides(int l, int r, string& s, int& ans) {
        while(l >= 0 && r < s.size() && s[l] == s[r])
            ans++, l--, r++;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 1) return 1;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            gosides(i, i, s, ans);
            gosides(i, i+1, s, ans);
        }
        
        return ans;
    }
};

// improving the iteration (storing the last indices) - O(n^2) time & space
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 1) return 1;
        
        int ans = n;
        array<vector<int>, 26> inds;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        inds[s[0]-'a'].push_back(0);
        for(int i = 1; i < n; i++) {
            for(int j: inds[s[i]-'a']) {
                if(i-j > 1)
                    dp[j][i] = dp[j+1][i-1];
                else 
                    dp[j][i] = 1;
                
                ans += dp[j][i];
            }
            
            inds[s[i]-'a'].push_back(i);
        }
        
        return ans;
    }
};

// simple dp O(N^2) space and time
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 1) return 1;
        
        int ans = n;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                dp[i-1][i] = 1;
                ans++;
            }
            
            for(int j = i-2; j >= 0; j--) {
                dp[j][i] = (s[i] == s[j] && dp[j+1][i-1]);
                ans += dp[j][i];
            }
        }
        
        return ans;
    }
};
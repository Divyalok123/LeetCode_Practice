/*
https://leetcode.com/contest/weekly-contest-229/problems/maximize-palindrome-length-from-subsequences/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void longestpalin(string w, vector<vector<int>>& dp, int sz) {
        for(int i = 0; i < sz; i++)
            dp[i][i] = 1;
        
        for(int l = 2; l <= sz; l++) {
            for(int i = 0; i <= sz-l; i++) {
                int li = i + l - 1;
                
                if(l == 2) {
                    if(w[i] == w[li]) dp[i][li] = 2;
                    else dp[i][li] = 1;
                } else {
                    if(w[i] == w[li]) dp[i][li] = dp[i+1][li-1] + 2;
                    else dp[i][li] = max(dp[i][li-1], dp[i+1][li]);
                } 
            }
        }
    }
    
    int longestPalindrome(string word1, string word2) {
        
        string ss = word1 + word2;
        int n = ss.size();
        vector<vector<int>> dp(n, vector<int>(n));
        longestpalin(ss, dp, n);
        
        int ans = 0;
        for(int i = 0; i < word1.size(); i++) {
            for(int j = 0; j < word2.size(); j++) {
                if(word1[i] == word2[j]) {
                    ans = max(ans, dp[i+1][word1.size() + j-1] + 2);
                }
            }
        }
        return ans;
    }
};
/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// improving to O(n2) space
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int total = 0;
        for(char& c: s1) total += c;
        for(char& c: s2) total += c;
        
        int dp[n2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n1; i++) {
            int newdp[n2+1];
            memset(newdp, 0, sizeof(newdp));
            
            for(int j = 1; j <= n2; j++) {
                if(s1[i-1] == s2[j-1])
                    newdp[j] = s1[i-1] + dp[j-1];
                else
                    newdp[j] = dp[j] > newdp[j-1] ? dp[j] : newdp[j-1];
            }
            
            for(int j = 0; j <= n2; j++)
                dp[j] = newdp[j];
        }
        
        return total - 2*dp[n2];
    }   
};


// improving to bottom-up dp - O(n1*n2) time & space
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int total = 0;
        for(char& c: s1) total += c;
        for(char& c: s2) total += c;
        
        int dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        
        return total - 2*dp[n1][n2];
    }   
};

// taking the LCS way - top down - O(n1*n2)
class Solution {
public:
    int n1, n2;
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& cache) {
        if(i == n1 || j == n2)
            return 0;
        
        if(cache[i][j] != -1)
            return cache[i][j];
        
        if(s1[i] == s2[j]) 
            return cache[i][j] = s1[i] + solve(s1, s2, i+1, j+1, cache);
        
        int a = solve(s1, s2, i+1, j, cache);
        int b = solve(s1, s2, i, j+1, cache);
        return cache[i][j] = max(a, b);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size(), n2 = s2.size();
        
        int total = 0;
        
        for(char& c: s1) total += c;
        for(char& c: s2) total += c;
        
        vector<vector<int>> cache(n1, vector<int>(n2, -1));
        return total - 2*solve(s1, s2, 0, 0, cache);
    }   
};

// finding the minimum deletions - top down - O(n1*n2)
class Solution {
public:
    vector<int> suff1, suff2;
    int n1, n2;
    int solve(string& s1, string& s2, int i, int j, int** cache) {
        if(i == n1 && j == n2)
            return 0;
        
        if(i == n1)
            return suff2[j];
        
        if(j == n2)
            return suff1[i];
        
        if(cache[i][j] != -1)
            return cache[i][j];
        
        if(s1[i] == s2[j]) 
            return cache[i][j] = solve(s1, s2, i+1, j+1, cache);
        
        int a = s1[i] + solve(s1, s2, i+1, j, cache);
        int b = s2[j] + solve(s1, s2, i, j+1, cache);
        return cache[i][j] = min(a, b);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size(), n2 = s2.size();
        
        suff1.resize(n1);
        suff2.resize(n2);
        suff1[n1-1] = s1[n1-1];
        suff2[n2-1] = s2[n2-1];
        
        for(int i = n1-2; i >= 0; i--)
            suff1[i] += suff1[i+1] + s1[i];
        
        for(int i = n2-2; i >= 0; i--)
            suff2[i] += suff2[i+1] + s2[i];
        
        int** cache = new int*[n1];
        for(int i = 0; i < n1; i++) {
            cache[i] = new int[n2];
            for(int j = 0; j < n2; j++)
                cache[i][j] = -1;
        }
        
        return solve(s1, s2, 0, 0, cache);
    }   
};
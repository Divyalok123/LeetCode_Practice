// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

//Solution 2 (dp) (passed)
class Solution {
    
public:
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        int dp[n+1][m+1];
        for(int i = 0; i < n+1; i++)
            dp[i][0] = i;
        for(int j = 0; j < m+1; j++)
            dp[0][j] = j;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < m+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        
        return dp[n][m];
    }
};

//Solution 1 (memoized) (TLE)
class Solution
{

public:
    int helper(string word1, string word2, int **memo)
    {
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0)
            return max(n, m);
        if (memo[n][m] != -1)
            return memo[n][m];

        int ans = 0;
        if (word1[0] == word2[0])
        {
            ans = helper(word1.substr(1), word2.substr(1), memo);
        }
        else
        {
            int a = 1 + helper(word1, word2.substr(1), memo);
            int b = 1 + helper(word1.substr(1), word2, memo);
            int c = 1 + helper(word1.substr(1), word2.substr(1), memo);
            ans = min(a, min(b, c));
        }

        memo[n][m] == ans;
        return ans;
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0)
            return max(n, m);

        int **memo = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            memo[i] = new int[m + 1];
            for (int j = 0; j < m + 1; j++)
            {
                memo[i][j] = -1;
            }
        }

        int result = helper(word1, word2, memo);
        for (int i = 0; i < n + 1; i++)
            delete[] memo[i];
        delete[] memo;

        return result;
    }
};
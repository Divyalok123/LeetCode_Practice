/*
https://leetcode.com/problems/stone-game/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// observation (https://leetcode.com/problems/stone-game/discuss/154610/DP-or-Just-return-true)
//Alex will always win because there are even no. of piles and total number of stones are odd..
//so he can take even piles or odd piles whichever is more and win the game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// bottom-up
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> prefix(n+1);
        for(int i = 1; i<=n; i++)
            prefix[i] += piles[i-1] + prefix[i-1];
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int d = 1; d < n; d++) {
            for(int i = 0; i < n-d; i++) {
                dp[i][i+d] = prefix[i+d+1]-prefix[i] - min(dp[i+1][i+d], dp[i][i+d-1]);
            }
        }
        
        return dp[0][n-1] > prefix[n]-dp[0][n-1];
    }
};

// top-down 
class Solution {
public:
    int helper(vector<int>& piles, int i, int j, vector<vector<int>>& dp, vector<int>& prefix) {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //taking i
        int a = helper(piles, i+1, j, dp, prefix);

        //taking j
        int b = helper(piles, i, j-1, dp, prefix);
        
        return dp[i][j] = prefix[j+1]-prefix[i] - min(a, b);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> prefix(n+1);
        for(int i = 1; i<=n; i++)
            prefix[i] += piles[i-1] + prefix[i-1];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = helper(piles, 0, n-1, dp, prefix);        
        return ans > prefix[n]-ans;
    }
};
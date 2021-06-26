/*
https://leetcode.com/problems/valid-permutations-for-di-sequence/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 2

     
// Solution 1
#define MOD 1000000007
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                if(S[i-1] == 'D') 
                    for(int k = j; k <= i-1; k++)
                        dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
                else 
                    for(int k = 0; k <= j-1; k++) 
                        dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
            }
        }
        
        cout << "DP" << endl;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        
        int ans = 0;
        for(int i = 0; i <= n; i++)
            ans = (ans + dp[n][i])%MOD;
        
        return ans;
    }
};
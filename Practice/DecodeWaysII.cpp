/*
https://leetcode.com/problems/decode-ways-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

/* Solution 1 */
#define ll long long
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        vector<ll> dp(n+1);
        ll MOD = 1000000007;
        dp[0] = 1;
        dp[1] = (s[0] == '*') ? 9 : 1;
        for(int i = 2; i <= n; i++) {
            if(s[i-1] == '0') {
                if(s[i-2] == '0' || s[i-2] > '2') return 0;
                if(s[i-2] == '*') dp[i] = 2*dp[i-2];
                else dp[i] = dp[i-2];
            } else if(s[i-1] <= '6' && s[i-1] >= '1') {
                dp[i] = dp[i-1];
                if(s[i-2] == '2' || s[i-2] == '1') dp[i] += dp[i-2];
                if(s[i-2] == '*') dp[i] += 2*dp[i-2];
            } else if(s[i-1] == '*') {
                dp[i] = 9*dp[i-1]%MOD;
                if(s[i-2] == '1') dp[i] += 9*dp[i-2];
                if(s[i-2] == '2') dp[i] += 6*dp[i-2];
                if(s[i-2] == '*') dp[i] += 15*dp[i-2];
            } else {
                dp[i] = dp[i-1];
                if(s[i-2] == '1' || s[i-2] == '*') dp[i] += dp[i-2];
            }
            dp[i] %= MOD;
        }
        
        return (int)dp[n];
    }
};
/*
https://leetcode.com/problems/2-keys-keyboard/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Improved
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for(int i = 2; i <= n; i++)
            while(n%i == 0) {
                ans += i;
                n/=i;
            }
        return ans;
    }
};

// O(1) space solution
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for(int i = n, j = 0; i >= 2; i = j) {
            for(j = i >> 1; j >= 1; j--)
                if(i%j == 0) {
                    ans += i/j;
                    break;
                }
        }
        return ans;
    }
};

// storing the ans
class Solution {
public:
    static vector<int> gett() {
        vector<int> dp(1001);
        for(int i = 2; i <= 1000; i++) {
            dp[i] = i;
            for(int j = i-1; j >= 1; j--)
                if(i%j==0) {
                    dp[i] = dp[j] + i/j;
                    break;
                }
        }
        return dp;
    }
    
    int minSteps(int n) {
        static auto results = gett();
        return results[n];    
    }
};


// simple dp - O(n^2)
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        
        int dp[n+1];
        dp[0] = dp[1] = 0;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = i;
            for(int j = i-1; j >= 1; j--)
                if(i%j==0) {
                    dp[i] = dp[j] + i/j;
                    break;
                }
        }
        
        return dp[n];
    }
};
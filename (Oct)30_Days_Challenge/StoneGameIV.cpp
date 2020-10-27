/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3507/
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/* Solution 2 */


/* Solution 1 */
class Solution {
    vector<int> dp;
    int isperfect(int n) {
        int x = sqrt(n);
        return (x*x) == n; 
    }
    
    bool check(int n) {
        if(n == 0)
            return false;
        
        if(dp[n] != -1)
            return dp[n];
        
        if(isperfect(n)) {
            return true;
        }
        
        for(int i = 1; i*i <= n; i++) {
            if(!check(n-(i*i)))
                return dp[n] = true;
        }
        return dp[n] = false;
    }
    
public:
    bool winnerSquareGame(int n) {
        if(n <= 2)
            return n&1;
        dp.assign(n+1, -1);
        return check(n);
    }
};
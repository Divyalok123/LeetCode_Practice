/*
https://leetcode.com/problems/airplane-seat-assignment-probability/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Observation (Not mine of course)
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};

// DP
class Solution {
public:
    double nthPersonGetsNthSeat(double n) {
        if(n == 1)
            return 1;
        
        vector<double> dp(n+1);
        dp[1] = 1;
        for(double i = 2; i <= n; i++)
            dp[i] = 1/i + (i-2)/i*dp[i-1];
        
        return dp[n];
    }
};

// Recursion
class Solution {
public:
    double nthPersonGetsNthSeat(double n) {
        if(n == 1)
            return 1;
        
        // this guy got his seat
        double a = 1.0/n;
        
        // this guy got a seat other than his and n's 
        double b = (n-2)/n * nthPersonGetsNthSeat(n-1);
        
        return (a + b);
    }
};
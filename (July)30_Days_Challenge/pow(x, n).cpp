/*
    Implement pow(x, n), which calculates x raised to the power n (xn).
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n == 0) return 1;
        if(x == 0) return 0;        
        long nn = abs((long)n);
        
        while(nn) {
            if(nn&1)
                ans *= x;
            x *= x;
            nn >>= 1;
        }
        
        return n < 0 ? 1/ans : ans;
        
    }
};
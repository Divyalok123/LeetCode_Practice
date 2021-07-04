/*
https://leetcode.com/contest/weekly-contest-248/problems/count-good-numbers/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    #define MOD 1000000007
    
    long long power(long long x, long long y) {
        int ans = 1;
        while(y) {
            if(y&1)
                ans = (ans * x) % MOD;
            y >>= 1;
            x = (x * x) % MOD;
        }
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        return (power(5, (n+1ll)/2) * power(4, n/2)) % MOD; 
    }
};
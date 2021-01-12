/*
https://leetcode.com/problems/ugly-number-iii/
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if(a==1 || b == 1 || c == 1) return n;
        if(a == b && b == c) return n*a;
        
        using ll = long long;
        
        auto ans = [](ll v, ll i, ll j, ll k) {
            ll x = j*k/__gcd(j, k);
            return (v/i + v/j + v/k - v/(i*j/__gcd(i, j)) - v/x - v/(i*k/__gcd(i, k)) + v/(i*x/__gcd(i, x)));
        };
        
        ll x = a, y = b, z = c, m, i = 1, j = 2*1e9;
        while(i < j) {
            m = i + (j-i)/2;
            if(ans(m, x, y, z) < n) i = m+1;
            else j = m;
        }
        
        return (int)j;
    }
};
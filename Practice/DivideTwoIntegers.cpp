/*
https://leetcode.com/problems/divide-two-integers/
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define MIN -2147483648
#define MAX 2147483647

/* Solution 2 */
class Solution {
public:
    int divide(int a, int b) {
        if (a == MIN && b == -1) return MAX;
        if (a == MIN && b == 1) return MIN;
        if (b == MIN) return a == MIN;
        int sign = (a < 0) ^ (b < 0) ? -1 : 1;
        int ans = 0;
        bool c = 0;
        
        if(a == MIN) {
            a = MAX;
            c=1;
        };
        
        a = abs(a);
        b = abs(b);
        
        for (int i = 31; i >= 0; i--)
        {
            if ((a >> i) >= b)
            {
                a -= (b << i);
                ans += (1<< i);
            }
        }

        if(c && ((a+1)==b)) ans++;
        return sign == -1 ? -ans : ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int divide(int A, int B) {
        if(A == 0)
            return 0;
        if(A == MIN && B == -1) return MAX;
        ll a = A;
        ll b = B;
        bool c = a < 0 ? (b < 0 ? 0 : 1) : (b < 0 ? 1 : 0);
        a = abs(a), b = abs(b);

        if(a < b)
            return 0;

        ll ans = exp(log(a)-log(b));
        return c ? -ans : ans;
    }
};
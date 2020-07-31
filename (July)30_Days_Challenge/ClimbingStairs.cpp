/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        int a = 1;
        int b = 1;
        using ll = long long;
        while (n)
        {
            ll c = (ll)a + (ll)b;
            a = b;
            b = c;
            n--;
        }
        return a;
    }
};
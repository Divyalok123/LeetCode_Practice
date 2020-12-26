/*
https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;

        long long ans = 0;
        while (x % 10 == 0)
            x /= 10;

        while (x)
        {
            ans *= 10;
            ans += x % 10;
            if (ans > INT_MAX || ans < INT_MIN)
                return 0;
            x /= 10;
        }

        return (int)ans;
    }
};
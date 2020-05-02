// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

#include <iostream>
#include <algorithm>

using namespace std;

//using most significant bit
class Solution
{
    int MSB(int n)
    {
        int ans = -1;
        while (n)
        {
            n = n >> 1;
            ans++;
        }
        return ans;
    }

public:
    int rangeBitwiseAnd(int m, int n)
    {
        int ans = 0;
        while (m && n)
        {
            int msb_n = MSB(n);
            int msb_m = MSB(m);

            if (msb_n != msb_m)
            {
                break;
            }

            int val = (1 << msb_n);
            ans += val;

            m = m - val;
            n = n - val;
        }
        return ans;
    }
};

//using least signicant bit
class Solution
{
    //using most significant bit
    int LSB(int n, int m)
    {
        while (n < m)
        {
            m -= (m & -m);
        }
        return m;
    }

public:
    int rangeBitwiseAnd(int n, int m)
    {
        int ans = LSB(n, m);
        return ans;
    }
};
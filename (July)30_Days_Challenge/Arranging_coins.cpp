// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
// Given n, find the total number of full staircase rows that can be formed.
// n is a non-negative integer and fits within the range of a 32-bit signed integer.

#include <iostream>
using namespace std;

/* --- Solution 3 --- */
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long s = 0, e = n;
        while (s <= e)
        {
            long m = s + (e - s) / 2;
            long val = (m * (m + 1)) / 2;
            if (val == (long)n)
            {
                return (int)m;
            }
            else if (val < (long)n)
                s = m + 1;
            else
                e = m - 1;
        }
        return (int)e;
    }
};

/* --- Solution 2 --- */
class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (int)((long long)sqrt(1 + (long long)8 * n) - 1) / 2;
    }
};

/* --- Solution 1 --- */
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int x = 1;
        int c = 0;
        while (x <= n)
        {
            c++;
            n -= x;
            x++;
        }
        return c;
    }
};
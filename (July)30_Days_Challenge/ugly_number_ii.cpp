// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

//Note: 1 is typically treated as an ugly number.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* --------- Solution 2 ----------- */


/* --------- Solution 1 ----------- */
class Solution
{
    long MAX = 2500000000;
    vector<long> weareugly;

    bool flag = false;

    void getuglies()
    {
        for (long i = 1; i < MAX; i *= 2)
            for (long j = i; j < MAX; j *= 3)
                for (long k = j; k < MAX; k *= 5)
                    weareugly.push_back(k);
        sort(weareugly.begin(), weareugly.end());
    }

public:
    int nthUglyNumber(int n)
    {
        if (!flag)
            getuglies();
        return (int)weareugly[n - 1];
    }
};
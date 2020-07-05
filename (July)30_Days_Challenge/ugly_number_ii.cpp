// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

//Note: 1 is typically treated as an ugly number.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/* --------- Solution 2 ----------- */
class Solution
{
    vector<int> uglies;
    bool flag = false;
    int index_2 = 0, index_3 = 0, index_5 = 0;
    
public:
    int nthUglyNumber(int n)
    {
        if(!flag) uglies.push_back(1);
        while (uglies.size() < n)
        {

            int minim = min(uglies[index_2] * 2, min(uglies[index_3] * 3, uglies[index_5] * 5));

            uglies.push_back(minim);

            if (minim == uglies[index_2] * 2)
                index_2++;
            if (minim == uglies[index_3] * 3)
                index_3++;
            if (minim == uglies[index_5] * 5)
                index_5++;
        }
        return uglies[n - 1];
    }
};

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
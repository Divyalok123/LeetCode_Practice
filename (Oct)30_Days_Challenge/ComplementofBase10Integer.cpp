/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3484/
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getallbitset(int x)
    {
        int ans = 0;
        while (x--)
            ans += pow(2, x);
        return ans;
    }

    int bitwiseComplement(int n)
    {
        if (n <= 1)
            return n ^ 1;
        int l = log2(n) + 1;
        l = getallbitset(l);
        return n ^ l;
    }
};
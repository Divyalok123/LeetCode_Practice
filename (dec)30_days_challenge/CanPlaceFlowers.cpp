/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3555/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &f, int n)
    {
        int sz = f.size();

        if (sz == 1)
            return (n == 0 || f[0] == 0);

        int i = 0, count = 0, c = 0;
        while (i < sz && f[i] == 0)
            i++;
        count = i / 2;

        if (i == sz && sz & 1)
            count++;

        int j = sz - 1;
        while (j > i && f[j] == 0)
            j--;
        count += (sz - j - 1) / 2;

        while (i < j)
        {
            c = 0;
            i++;

            while (i < j && f[i] == 0)
                i++, c++;

            count += (c - 1) / 2;
        }

        return count >= n;
    }
};
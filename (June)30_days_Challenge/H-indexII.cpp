// Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
/*   According to the definition of h-index on Wikipedia: 
    "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each." */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &c)
    {
        int size = c.size();
        int s = 0;
        int e = size - 1;
        int ans = 0;
        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (c[m] >= (size - m))
            {
                ans = size - m;
                e = m - 1;
            }
            else
                s = m + 1;
        }

        return ans;
    }
};
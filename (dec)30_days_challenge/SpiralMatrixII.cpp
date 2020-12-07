/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3557/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 1)
            return {{1}};
            
        vector<vector<int>> v(n, vector<int>(n));

        int put = 1;
        int r = 0, c = 0, ce = n - 1, re = n - 1;
        while (put <= n * n)
        {
            for (int i = c; i <= ce; i++)
                v[r][i] = put++;

            r++;
            for (int i = r; i <= re; i++)
                v[i][ce] = put++;

            ce--;
            for (int i = ce; i >= c; i--)
                v[re][i] = put++;

            re--;
            for (int i = re; i >= r; i--)
                v[i][c] = put++;

            c++;
        }

        return v;
    }
};
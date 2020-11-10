/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3526/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int m = A[0].size();
        int i, j, t;

        for (int r = 0; r < A.size(); r++)
        {
            i = 0, j = m - 1;
            while (i <= j)
            {
                t = A[r][i];
                A[r][i] = 1 - A[r][j];
                A[r][j] = 1 - t;
                i++, j--;
            }
        }

        return A;
    }
};
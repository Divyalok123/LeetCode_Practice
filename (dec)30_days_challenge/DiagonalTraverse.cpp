/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3580/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (n == 0)
            return {};
        int m = mat[0].size();

        vector<int> ans(n * m);
        int k = 0, i = 0, j = 0, p = 1;
        while (k < n * m)
        {
            ans[k++] = mat[i][j];
            if (p == 1)
            {
                j++, i--;
                if (j == m)
                {
                    j--, i += 2;
                    p ^= 1;
                }
                else if (i == -1)
                {
                    i++;
                    p ^= 1;
                }
            }
            else
            {
                i++, j--;
                if (i == n)
                {
                    i--, j += 2;
                    p ^= 1;
                }
                else if (j == -1)
                {
                    j++;
                    p ^= 1;
                }
            }
        }

        return ans;
    }
};

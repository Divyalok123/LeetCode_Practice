// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        int** dp = new int*[n];
        for(int i = 0; i < n; i++)
        {
            dp[i] = new int[m];
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
        }

        for (int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                else
                    dp[i][j] = 0;
            }
        }

        int max = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;

        return max * max;
    }
};
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int sum = 0;
        int dp[305][305];
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];

        }

        cout << sum << endl;
        
        for(int i = 1; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
            sum += dp[0][i];
        }
        
        cout << sum << endl;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                    sum += dp[i][j];
                    cout << sum << endl;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        return sum;
    }
};
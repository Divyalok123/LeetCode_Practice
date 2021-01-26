/*
https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        
        for(int i = 0; i < n; i++) 
            if(matrix[i][0] == 1)
                dp[i][0] = 1, ans++;
            
        
        for(int j = 1; j < m; j++) 
            if(matrix[0][j] == 1) 
                dp[0][j] = 1, ans++;
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 1) {
                    int minv = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
                    dp[i][j] = (minv+1);
                    ans += dp[i][j];
                }
            }
        
        return ans;
    }
};
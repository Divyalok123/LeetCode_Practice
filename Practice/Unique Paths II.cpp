/*
https://leetcode.com/problems/unique-paths-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obsg) {
        int m = obsg.size(), n = obsg[0].size();
        if(obsg[0][0] == 1 || obsg[m-1][n-1] == 1)
            return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n));
        
        int i = 0;
        while(i < n && obsg[0][i] != 1)
            dp[0][i++] = 1;
        
        i = 0;
        while(i < m && obsg[i][0] != 1)
            dp[i++][0] = 1;
        
        for(i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obsg[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
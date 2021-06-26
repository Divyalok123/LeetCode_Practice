/*
https://leetcode.com/problems/matrix-block-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int premat[n+1][m+1];
        memset(premat, 0, sizeof(premat));
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                premat[i][j] = premat[i-1][j] + premat[i][j-1] - premat[i-1][j-1] + mat[i-1][j-1];   
        
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int ri = min(n, i+k+1), rj = min(m, j+k+1);
                int li = max(0, i-k), lj = max(0, j-k);
                
                ans[i][j] = premat[ri][rj] + premat[li][lj] - premat[li][rj] - premat[ri][lj];
            }
        }
        
        return ans;
    }
};
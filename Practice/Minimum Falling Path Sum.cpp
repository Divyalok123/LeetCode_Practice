/*
https://leetcode.com/problems/minimum-falling-path-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        if(n == 1) {
            int sum = 0;
            for(int i = 0; i < m; i++) sum += matrix[i][0];
            return sum;
        }
        
        for(int i = 1; i < m; i++) {
            matrix[i][0] += min(matrix[i-1][0], matrix[i-1][1]);
            
            for(int j = 1; j < n-1; j++) {
                int minv = min(matrix[i-1][j], matrix[i-1][j-1]);
                minv = min(minv, matrix[i-1][j+1]);
                matrix[i][j] += minv;
            }
            
            matrix[i][n-1] += min(matrix[i-1][n-1], matrix[i-1][n-2]);
        }
        
        int minv = INT_MAX;
        for(int& i: matrix[m-1])
            if(minv > i)
                minv = i;
        
        return minv;
    }
};
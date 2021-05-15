/*
https://leetcode.com/problems/spiral-matrix/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        int count = m*n, i = 0, j = 0, k = 0;
        vector<int> ans(count);
        while(count) {
            for(int l = j; count && l < n; l++)
                ans[k++] = matrix[i][l], count--;
            
            i++;
            for(int l = i; count && l < m; l++)
                ans[k++] = matrix[l][n-1], count--;
            
            n--;
            for(int l = n-1; count && l >= j; l--)
                ans[k++] = matrix[m-1][l], count--;
        
            m--;
            for(int l = m-1; count && l >= i; l--)
                ans[k++] = matrix[l][j], count--;
            
            j++;
        }
        
        return ans;
    }
};
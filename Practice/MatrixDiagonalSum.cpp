/*
https://leetcode.com/problems/matrix-diagonal-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

/* SOlution 2 */
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if(n == 1)
            return mat[0][0];
        
        int ans = 0, i = 0, j = n-1;
        while(i <= j) {
            if(i == (m-i-1))
                ans += mat[i][i];
            else ans += mat[i][i] + mat[i][m-i-1];
            
            if(i == j)
                break;
            
            if(j == (m-j-1))
                ans += mat[j][j];
            else ans += mat[j][j] + mat[j][m-j-1];
            
            i++,j--;
        }
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if(n == 1)
            return mat[0][0];
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i == (m-i-1))
                ans += mat[i][i];
            else ans += mat[i][i] + mat[i][m-i-1];
        }
        
        return ans;
    }
};
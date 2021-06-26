/*
https://leetcode.com/problems/rotate-image/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void printMatrix(vector<vector<int>>& mat) {
        for(auto& i: mat) {
            for(auto& j: i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 1) return;
        
        int lim = n/2;
        for(int i = 0; i < lim; i++) {
            for(int j = i; j < n-i-1; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n-j-1][i];
                mat[n-j-1][i] = mat[n-i-1][n-j-1];
                mat[n-i-1][n-j-1] = mat[j][n-i-1];
                mat[j][n-i-1] = temp;
            }
        }
    }
};
/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3650/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1, val;
        
        while(i < n && j >= 0) {
            val = matrix[i][j];
            if(val == target) return 1;
            else if(val < target) i++;
            else j--;
        }
        
        return 0;
    }
};
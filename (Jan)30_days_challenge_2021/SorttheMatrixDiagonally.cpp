/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3614/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> v;
        
        for(int i = n-1; i >= 0; i--) {
            int l = 0, k = i, j = 0;
            v.resize(min(n-i, m));
            while(k < n && j < m) 
                v[l++] = mat[k++][j++];
            
            sort(v.begin(), v.end());
            k = i, j = 0, l = 0;
            while(k < n && j < m) 
                mat[k++][j++] = v[l++];
        }
        
        for(int j = 1; j < m; j++) {
            v.resize(min(n, m-j));
            int k = j, i = 0, l = 0;
            while(k < m && i < n) 
                v[l++] = mat[i++][k++];
            
            sort(v.begin(), v.end());
            k = j, i = 0, l = 0;
            while(k < m && i < n)
                mat[i++][k++] = v[l++];
        }
        
        return mat;
    }
};
/*
https://leetcode.com/problems/spiral-matrix-iii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namesapce std;

// Solution 1
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R*C;
        vector<vector<int>> ans(total);

        int pointi = r0, pointj = c0;
        
        char D = 'R';
        ans[0] = {pointi, pointj};
        int i = 1, length = 1, height = 1;
        while(i < total) {
            bool check = true;
            if(D == 'R') {
                for(int j = 0; j < length; j++)
                {
                    pointj++;
                    if(pointi >= 0 && pointi < R && pointj < C && pointj >= 0)
                        ans[i++] = {pointi, pointj};
                    
                    if(i >= total) break;
                }
                length++;
                D = 'D';
            } else if(D == 'D') {
                for(int j = 0; j < height; j++)
                {
                    pointi++;
                    if(pointi >= 0 && pointi < R && pointj < C && pointj >= 0)
                        ans[i++] = {pointi, pointj};
                    
                    if(i >= total) break;
                }
                height++;
                D = 'L';
            } else if(D == 'U') {
                for(int j = 0; j < height; j++) {
                    pointi--;
                    if(pointi >= 0 && pointi < R && pointj < C && pointj >= 0)
                        ans[i++] = {pointi, pointj};
                    
                    if(i >= total) break;
                }
                height++;
                D = 'R';
            } else {
                for(int j = 0; j < length; j++) {
                    pointj--;
                    if(pointi >= 0 && pointi < R && pointj < C && pointj >= 0)
                        ans[i++] = {pointi, pointj};
                    
                    if(i >= total) break;
                }
                length++;
                D = 'U';
            }
        }
        
        return ans;
    }
};
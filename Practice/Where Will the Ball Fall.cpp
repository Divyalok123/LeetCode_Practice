/*
https://leetcode.com/problems/where-will-the-ball-fall/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> fans(n, -1);
    
        for(int i = 0; i < n; i++) {
            int curindi = 0;
            int curindj = i;
            while(curindi < m) {
                if(grid[curindi][curindj] == -1) {
                    if(curindj == 0) break;
                    else if(grid[curindi][curindj-1] == -1) curindj--, curindi++;
                    else break;
                } else {
                    if(curindj == n-1) break;
                    else if(grid[curindi][curindj+1] == 1) curindj++, curindi++;
                    else break;
                }
            }
            
            if(curindi == m)
                fans[i] = curindj;
        }
        
        return fans;
    }
};
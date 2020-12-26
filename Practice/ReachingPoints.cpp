/*
https://leetcode.com/problems/reaching-points/
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Iterative */


/* Recursive */
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty, int p = -1) {
        if(sx > tx || sy > ty) return 0;
        
        if(sx == tx)
            return (ty-sy)%sx == 0;
        if(sy == ty)
            return (tx-sx)%sy == 0;
        
        if(p == -1){
            if(tx < ty) p = 0;
            else p = 1;
        }
        
        if(p == 1)
            return reachingPoints(sx, sy, tx%ty, ty, p ^= 1);
        return reachingPoints(sx, sy, tx, ty%tx, p ^= 1);
    }
};
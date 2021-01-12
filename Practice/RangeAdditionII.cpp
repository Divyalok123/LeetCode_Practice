/*
https://leetcode.com/problems/range-addition-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m*n;
        
        int minx = m, miny = n;
        for(auto& i: ops)
        {
            if(minx > i[0]) minx = i[0];
            if(miny > i[1]) miny = i[1];
        }
        
        return minx*miny;
    }
};
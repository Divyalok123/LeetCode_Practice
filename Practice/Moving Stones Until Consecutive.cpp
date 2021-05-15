/*
https://leetcode.com/problems/moving-stones-until-consecutive/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> n = {a, b, c};
        sort(n.begin(), n.end());
        a = n[0], b = n[1], c = n[2];
        int x = abs(a-b)-1;
        int y = abs(b-c)-1;
        int maxim = x + y;
        int minim = (!x && !y) ? 0 : ((x > 1 && y > 1) ? 2 : 1); 
        return {minim, maxim};
    }
};
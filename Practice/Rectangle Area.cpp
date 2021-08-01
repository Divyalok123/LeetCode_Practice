/*
https://leetcode.com/problems/rectangle-area/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        
        if(ax2 <= bx1 || ay1 >= by2 || ay2 <= by1 || ax1 >= bx2)
            return area1 + area2;
        
        //first case
        int l1 = max(ax1, bx1);
        int d1 = max(ay1, by1);
        int u1 = min(ay2, by2);
        int r1 = min(ax2, bx2);
        
        return area1 + area2 - (u1-d1)*(r1-l1);
    }
};
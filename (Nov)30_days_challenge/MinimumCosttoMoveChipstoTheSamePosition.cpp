/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3520/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(auto& a: position) {
            if(a&1)
                odd++;
            else
                even++;
        }
        
        return min(odd, even);
    }
};
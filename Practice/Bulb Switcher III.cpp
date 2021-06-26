/*
https://leetcode.com/problems/bulb-switcher-iii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int maxval = INT_MIN, ans = 0;
        for(int i = 0; i < light.size(); i++) {
            if(light[i] > maxval)
                maxval = light[i];
            
            if(i+1 == maxval)
                ans++;
        }
        return ans;
    }
};
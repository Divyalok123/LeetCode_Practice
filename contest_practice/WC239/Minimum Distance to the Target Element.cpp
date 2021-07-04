/*
https://leetcode.com/contest/weekly-contest-239/problems/minimum-distance-to-the-target-element/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(target == nums[i])
                ans = min(ans, abs(i-start));
        }
        return ans;
    }
};
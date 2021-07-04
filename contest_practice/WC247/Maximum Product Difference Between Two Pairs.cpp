/*
https://leetcode.com/contest/weekly-contest-247/problems/maximum-product-difference-between-two-pairs/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};
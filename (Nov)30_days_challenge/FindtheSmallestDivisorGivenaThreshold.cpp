/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3521/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculate(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            double tsum = (double)nums[i]/divisor;
            if(tsum-(int)tsum == 0.0) sum += (int)tsum;
            else sum += (int)tsum+1;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = nums[nums.size()-1];

        while (lo <= hi) {
            int mid = (lo + hi)/2;
            int curr = calculate(nums, mid);

            if (curr > threshold) 
                lo = mid+1;
            else
                hi = mid-1;
        }

        return lo;
    }
};
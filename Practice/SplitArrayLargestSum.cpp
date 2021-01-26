/*
https://leetcode.com/problems/split-array-largest-sum/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 1 (Binary Search) */
class Solution {
public:
    bool check(vector<int>& nums, int val, int m) {
        int sum = 0, count = 0;
        int n = nums.size(), i = 0;
        
        while(i < n) {
            while(i < n && sum + nums[i] <= val) {
                sum += nums[i];
                i++;
            }
            sum = 0;
            count++;
            if(count > m)
                return false;
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int total = 0;
        for(int& i: nums)
            total += i;
        
        int i = 0, j = total;
        while(i < j) {
            int mid = i + (j-i)/2;
            if(check(nums, mid, m))
                j = mid;
            else
                i = mid+1;
        }
        
        return i;
    }
};
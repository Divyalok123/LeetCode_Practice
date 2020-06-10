// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int index = -1;
        int ans;
        int start = 0;
        int end = nums.size()-1;
        
        int mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(nums[mid] == target) { return mid;}
            else if(nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return start;
    }
};
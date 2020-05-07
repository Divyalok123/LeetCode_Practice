// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -∞.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if(0 == n) return -1;
        if(1 == n) return 0;
        if(2 == n) return nums[0] > nums[1] ? 0 : 1;
        // 
        int low = 0, high = n - 1;
        while(low + 2 <= high)
        {
            int mid = low + (high - low) / 2;            
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            if(nums[mid - 1] > nums[mid])
                high = mid;
            else
                low = mid;
        }
        // 
        return nums[low] > nums[high] ? low : high;
    }
};

//A really cool way
class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                return i-1;
            }
        }
        return nums.size()-1;
    }
};
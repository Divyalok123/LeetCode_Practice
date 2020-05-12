// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

//  Note: Your solution should run in O(log n) time and O(1) space.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            int mid = start + (end-start)/2;
            if(mid%2 == 0)//if mid is even then we have even number of element on both sides
            {
                if(nums[mid] == nums[mid+1]) start = mid + 2;
                else end = mid;
            }
            else
            {
                if(nums[mid] == nums[mid+1]) end = mid-1;
                else start = mid+1;
            }
        }
        
        return nums[start];
    }
};


//A really nice solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == nums[mid ^ 1])
                start = mid+1;
            else
                end = mid;
        }
        
        return nums[start];
    }
};
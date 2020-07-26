/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

static int x = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            if(nums[start] < nums[end])
                return nums[start];
            
            int mid = start + (end-start)/2;
            if(nums[mid] < nums[start])
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }
};
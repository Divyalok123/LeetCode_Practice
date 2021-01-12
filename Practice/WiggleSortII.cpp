/*
https://leetcode.com/problems/wiggle-sort-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 1 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        
        int i = n-1, j = (n-1)/2, k = 0;
        while(j >= 0) {
            ans[k++] = nums[j--];
            if(i > (n-1)/2) 
                ans[k++] = nums[i--];
        }
        
        nums = ans;
    }
};

/*-----------*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        
        if (size < 2) {
            return;
        }
        
        int mid = (size-1)/2;
        findMid(nums, 0, size - 1, mid);
        
        int smaller = mid;
        int larger = size - 1;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i += 2) {
            result[i] = nums[smaller];
            smaller--;
            if (i + 1 < size) {
                result[i + 1] = nums[larger];
                larger--;
            }
        }
        
        nums = result;
    }
    
    void findMid(vector<int>& nums, int start, int end, int k) {
        if (start == end) {
            return;
        }
        int left = start;
        int right = end;
        int mid = left + (right - left) / 2;
        int pivot = nums[mid];
        mid = start;
        while (mid <= right) {
            if (nums[mid] < pivot) {
                swap1(nums, left, mid);
                left++;
                mid++;
            } else if (nums[mid] > pivot) {
                swap1(nums, mid, right);
                right--;
            } else {
                mid++;
            }
        }
        
        if (k <= left) 
            findMid(nums, start, left, k);
        else if (k >= mid) 
            findMid(nums, mid, end, k);
    }
    
    void swap1(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}; 
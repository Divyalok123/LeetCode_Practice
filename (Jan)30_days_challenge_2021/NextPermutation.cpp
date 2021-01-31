/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3623/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Solution 2 O(n) in-place
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        
        while(j > 0 && nums[j-1] >= nums[j]) 
            j--;
        
        reverse(nums.begin()+j, nums.end());
        
        if(j != 0) {
            int i = j-1;
            while(j < n && nums[j] <= nums[i])
                j++;
            if(j < n) swap(nums[i], nums[j]);
        }
    }
};

//Solution 1 O(nlogn) in-place
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        
        while(j > 0 && nums[j-1] >= nums[j])
            j--;
        
        // cout << "j: " << j << endl;
        sort(nums.begin() + j, nums.end());
        
        if(j != 0) {
            int ind = j-1;
            while(j < n && nums[j] <= nums[ind])
                j++;
            if(j != n) 
                swap(nums[ind], nums[j]);
        }
    }
};
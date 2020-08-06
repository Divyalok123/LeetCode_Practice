/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output;
        for(auto a: nums) {
            nums[abs(a)-1] *= -1;
            if(nums[abs(a)-1] > 0) output.push_back(abs(a));
        }
        return output;
    } 
}; 

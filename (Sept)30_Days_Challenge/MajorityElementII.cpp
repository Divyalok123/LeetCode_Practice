/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int lim = nums.size()/3;
        vector<int> ans;
        
        int count1 = 0, count2 = 0, ele1 = -1, ele2 = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == ele1) count1++; 
            else if(nums[i] == ele2) count2++;
            else if(count1 == 0) ele1 = nums[i], count1 = 1;
            else if(count2 == 0) ele2 = nums[i], count2 = 1;
            else count1--,count2--;
        }
        
        // cout << "ele1: " << ele1 << " ele2: " << ele2 << endl;
        int count_1 = 0, count_2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == ele1) count_1++;
            else if(nums[i] == ele2) count_2++;
        }
        // cout << "count_1: " << count_1 << " count_2: " << count_2 << endl;
        if(count_1 > lim) ans.push_back(ele1);
        if(count_2 > lim) ans.push_back(ele2);
        return ans;
    }
};
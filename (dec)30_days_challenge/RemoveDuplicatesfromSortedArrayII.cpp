/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3562/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 0, j = 0;
        
        while(j < n) {
            nums[i++] = nums[j];
            if(j < n-1 && nums[j] == nums[j+1])
                nums[i++] = nums[j++];
            
            while(j < n-1 && nums[j] == nums[j+1])
                j++;
            
            j++;
        }
        
        return i;
    }
};
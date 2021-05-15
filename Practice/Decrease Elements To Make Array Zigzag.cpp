/*
https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1
class Solution {
public:
    
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        
        //even case
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) {
            int l = i == 0 ? 10000 : nums[i-1];
            int r = i == n-1 ? 10000 : nums[i+1];
            
            if(i&1)
                count1 += max(0, l < r ? nums[i]-l+1 : nums[i]-r+1);
            else 
                count2 += max(0, l < r ? nums[i]-l+1 : nums[i]-r+1);
            
        }
        
        return min(count1, count2);
    }
};
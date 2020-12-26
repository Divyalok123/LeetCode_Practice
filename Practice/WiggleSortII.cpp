/*
https://leetcode.com/problems/wiggle-sort-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 2 */


/* Solution 1 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int i = n-1, j = ((n+1)/2) - 1;
        while(j >= 0) {
            ans.push_back(nums[j--]);
            if(i > ((n+1)/2)-1)ans.push_back(nums[i--]);
        }
        
        
        nums = ans;
    }
};
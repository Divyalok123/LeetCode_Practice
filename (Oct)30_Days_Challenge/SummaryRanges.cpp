/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3510/
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int c1;
        vector<string> ans;
        
        int i = 0;
        while(i < nums.size()) {
            c1 = i;
            i++;
            while(i < nums.size() && (nums[i] == nums[i-1]+1))
                i++;
            if(i-1 != c1)
                ans.push_back(to_string(nums[c1]) + "->" + to_string(nums[i-1]));
            else 
                ans.push_back(to_string(nums[c1]));
        }
        
        return ans;
    }
};
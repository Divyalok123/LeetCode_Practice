/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3611/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int kk = n-k;
        
        if(k == 0) return nums;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            while(kk && ans.size() && ans.back() > nums[i])
                ans.pop_back(), kk--;
            ans.push_back(nums[i]);
        }
        
        while(kk && ans.size())
            ans.pop_back(), kk--;
        
        return ans;
    }
};
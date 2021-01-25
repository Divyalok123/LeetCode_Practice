/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int ind = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                if(ind == -1)
                    ind = i;
                else {
                    if(i-ind-1 < k) return false;
                    ind = i;
                }
            }
        }
        
        return 1;
    }
};
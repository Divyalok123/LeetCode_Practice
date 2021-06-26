/*
https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> cache;
    #define initial 1000000007
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int MASK) {
        if(i == nums1.size())
            return 0;
        
        int& ans = cache[MASK];
        if(ans != initial)
            return ans;
        
        for(int j = 0, bit = 1; j < nums2.size(); j++, bit <<= 1) {
            if(MASK & bit) continue;
            int val = (nums1[i]^nums2[j]) + helper(nums1, nums2, i+1, MASK | bit);
            if(ans > val)
                ans = val;
        }
        
        return ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        cache.resize((1 << n)-1, initial);
        return helper(nums1, nums2, 0, 0);
    }
};
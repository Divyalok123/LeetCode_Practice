/*
https://leetcode.com/problems/tuple-with-same-product/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        unordered_map<int, int> m;
        for(int i  = 0; i < n; i++) 
            for(int j = i+1; j < n; j++) {
                auto& re = m[nums[i]*nums[j]];
                ans += re;
                re++;
            }
        
        return ans*8;
    }
};
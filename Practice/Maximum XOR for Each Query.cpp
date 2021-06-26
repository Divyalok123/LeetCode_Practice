/*
https://leetcode.com/problems/maximum-xor-for-each-query/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Improved
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorr = 0;
        int bits = (1 << maximumBit)-1;

        vector<int> ansvec(n);
        for(int i = n-1; i >= 0; i--) {
            xorr ^= nums[n-i-1];
            ansvec[i] = (bits^xorr);
        }
        
        return ansvec;
    }
};

// solution 1
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorr = 0;
        for(int& i: nums)
            xorr ^= i;
        
        vector<int> ansvec(n);
        int j = 0;
        while(n--) {
            int val = xorr;
            int ans = 0;
            for(int i = 0; i < maximumBit; i++)
                if((val&(1 << i)) == 0)
                    ans |= (1 << i);
            
            ansvec[j++] = ans;
            xorr ^= nums[n];
        }
        
        return ansvec;
    }
};
/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3606/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int quickselect(vector<int>& nums, int i, int j) {
        int len = j-i+1;
        int rind = i + rand()%len;
        
        swap(nums[j], nums[rind]);
        int l = 0, r = 0;
        while(r < j) {
            if(nums[r] <= nums[j]) {
                swap(nums[r], nums[l]);
                l++;
                r++;
            } else r++;
        }
        
        swap(nums[l], nums[j]);
        return l;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(0);
            
        int n = nums.size();
        k = n-k;
        
        int m, i = 0, j = n-1;
        while(i <= j) {
            m = quickselect(nums, i, j);
            if(m == k) return nums[k];
            
            if(k > m) i = m+1;
            else j = m-1;
        }
        
        return -1;
    }
};
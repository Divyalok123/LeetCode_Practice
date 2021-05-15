/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

// Binary Search & Sliding Window - O(nlog(maxval-minval))
class Solution {
public:
    
    int islessorequal(vector<int>& nums, int m) {
        int count = 0;
        int n = nums.size();
        int i = 0, j = i+1;
        
        while(j < n) {
            if(nums[j]-nums[i] <= m)
                count += (j-i), j++;
            else 
                while(i < j && nums[j]-nums[i] > m)
                    i++;
        }
        
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.back()-nums.front();
        while(l < r) {
            int m = l + (r-l)/2;
            
            int count = islessorequal(nums, m);
            
            if(count < k)
                l = m+1;
            else
                r = m;            
        } 
        
        return l;    
    }
};
/*
https://leetcode.com/problems/total-hamming-distance/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// improved
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < 30; i++) {
            int val = (1 << i);
            int count = 0;
            for(int& j: nums) 
                if(val&j) count++;
            ans += count*(n-count);
        }
        
        return ans;
    }
};

//naive solution
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int counts[30] = {0};
    
        for(int i = 0; i < 30; i++) {
            int val = (1 << i);
            for(int& j: nums) 
                if(val&j) counts[i]++;
        }
        
        int ans = 0;
        for(int i = 0; i < 30; i++)
            ans += (n-counts[i])*counts[i];
        
        return ans;
    }
};
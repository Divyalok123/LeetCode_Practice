/*
https://leetcode.com/contest/weekly-contest-238/problems/frequency-of-the-most-frequent-element/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        long long count = 0, sum = 0, last = nums[0];
        int ans = 0;
        while(j < n) {
            sum += (nums[j]-last)*(j-i);
            while(sum > k && i < j) {
                sum -= (nums[j]-nums[i]);
                i++;
            }
            
            ans = max(ans, j-i+1);
            last = nums[j];
            j++;
        }
        
        return ans;
    }
};

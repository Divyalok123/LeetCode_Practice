// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        //Better solution
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
                count++;
            if (mp[sum - k])
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};
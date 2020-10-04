/*
https://leetcode.com/problems/number-of-good-pairs/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mm;
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
            count += mm[nums[i]]++;
        return count;
    }
};
// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> output;
        output.push_back({});
        for (int i = 0; i < nums.size(); i++)
        {
            int n = output.size();
            for (int j = 0; j < n; j++)
            {
                output.push_back(output[j]);
                output.back().push_back(nums[i]);
            }
        }

        return output;
    }
};
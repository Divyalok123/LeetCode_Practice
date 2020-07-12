// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Solution 2
class Solution
{
public:
    void helper(vector<int> &nums, int ind, vector<int> &temp, vector<vector<int>> &output)
    {
        output.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(nums, i + 1, temp, output);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> temp;

        helper(nums, 0, temp, output);

        return output;
    }
};

//Solution 1
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



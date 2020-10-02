/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, int sum, int ind, vector<vector<int>> &ans, vector<int> &v)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i, ans, v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
        {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> v;
        dfs(candidates, target, 0, 0, ans, v);
        return ans;
    }
};
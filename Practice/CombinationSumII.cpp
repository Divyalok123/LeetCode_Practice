/*
https://leetcode.com/problems/combination-sum-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            v.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i + 1, ans, v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if (candidates.size() == 0)
            return {};

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        dfs(candidates, target, 0, 0, ans, v);
        return ans;
    }
};
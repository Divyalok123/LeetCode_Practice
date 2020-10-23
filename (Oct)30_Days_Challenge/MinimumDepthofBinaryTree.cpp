/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3504/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int ans = INT_MAX;
    void helper(TreeNode *root, int curr)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            ans = min(ans, curr);
            return;
        }

        helper(root->left, curr + 1);
        helper(root->right, curr + 1);
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        helper(root, 1);
        return ans;
    }
};
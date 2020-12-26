/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Solution 2 */
class Solution
{
public:
    int maxcount = 1;
    int count = 0;
    int prev = -1;
    void dfs(TreeNode *root)
    {
        if (!root)
        {
            if (maxcount < count)
                maxcount = count;
            return;
        }
        dfs(root->left);
        if (root->val == prev)
            count++;
        else
        {
            if (maxcount < count)
                maxcount = count;
            count = 1;
        }
        prev = root->val;
        dfs(root->right);
    }

    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }

        dfs(root->left, ans);
        if (root->val == prev)
            count++;
        else
            count = 1;

        if (count == maxcount)
            ans.push_back(root->val);

        prev = root->val;
        dfs(root->right, ans);
    }

    vector<int> findMode(TreeNode *root)
    {
        dfs(root);
        vector<int> ans;
        count = 0, prev = -1;
        dfs(root, ans);
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    unordered_map<int, int> umap;

    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        umap[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        dfs(root);
        int maxel = INT_MIN;
        for (auto &a : umap)
        {
            if (a.second > maxel)
                maxel = a.second;
        }

        vector<int> ans;
        for (auto &a : umap)
        {
            if (a.second == maxel)
                ans.push_back(a.first);
        }

        return ans;
    }
};
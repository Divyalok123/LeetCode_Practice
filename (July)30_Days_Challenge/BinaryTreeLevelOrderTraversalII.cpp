// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> output;

        if (root == NULL)
            return output;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        // output.push_back({root->val});
        int level = -1;
        while (!q.empty())
        {
            pair<TreeNode *, int> temp = q.front();
            q.pop();

            TreeNode *tempnode = temp.first;
            int templevel = temp.second;

            if (templevel != level || level == -1)
            {
                output.push_back({tempnode->val});
            }
            else
                output[templevel].push_back(tempnode->val);

            if (tempnode->left != NULL)
                q.push({tempnode->left, templevel + 1});

            if (tempnode->right != NULL)
                q.push({tempnode->right, templevel + 1});
            level = templevel;
        }

        reverse(output.begin(), output.end());
        return output;
    }
};
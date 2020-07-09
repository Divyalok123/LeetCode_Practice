// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

#include <iostream>
#include <queue>
#include <algorithm>
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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, long long>> q;
        // vector<TreeNode*> v;

        int maxim = 1;
        q.push({root, 1});
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            long long f = q.front().second, s = -1;
            while (size--)
            {
                pair<TreeNode *, int> n = q.front();
                q.pop();

                TreeNode *node = n.first;
                long long val = n.second;
                s = val;
                if (node->left)
                    q.push({node->left, 2 * val});
                if (node->right)
                    q.push({node->right, 2 * val + 1});
            }

            if ((int)(s - f + 1) > maxim)
            {
                maxim = (int)(s - f + 1);
            }
            level++;
        }
        return maxim;
    }
};
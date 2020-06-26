// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// Note: A leaf is a node with no children.

#include <iostream>
#include <algorithm>
#include <queue>
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

/* -- DFS -- */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void help(TreeNode *r, int c, int &a)
    {
        if (r->left == NULL && r->right == NULL)
        {
            a += (c * 10 + r->val);
            return;
        }
        if (r->left != NULL)
            help(r->left, c * 10 + r->val, a);
        if (r->right != NULL)
            help(r->right, c * 10 + r->val, a);
    }

    int sumNumbers(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        if (r->left == NULL && r->right == NULL)
            return r->val;
        int a = 0;
        help(r, 0, a);
        return a;
    }
};

/* -- BFS -- */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return root->val;

        int ans = 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, root->val});

        while (!q.empty())
        {
            pair<TreeNode *, int> node = q.front();
            q.pop();

            TreeNode *newNode = node.first;
            int val = node.second;

            if (newNode->left == NULL && newNode->right == NULL)
            {
                ans += val;
            }
            else
            {
                if (newNode->left != NULL)
                {
                    q.push({newNode->left, val * 10 + newNode->left->val});
                }

                if (newNode->right != NULL)
                {
                    q.push({newNode->right, val * 10 + newNode->right->val});
                }
            }
        }

        return ans;
    }
};
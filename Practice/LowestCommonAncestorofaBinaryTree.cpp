/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution 2 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *fromLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *fromRight = lowestCommonAncestor(root->right, p, q);

        if (fromLeft && fromRight)
            return root;
        if (fromLeft)
            return fromLeft;
        return fromRight;
    }
};

/* Solution 1 */
class Solution
{
public:
    void getpath(TreeNode *root, TreeNode *p, vector<int> &v)
    {
        if (!root)
        {
            v.clear();
            return;
        }

        if (root->val == p->val)
        {
            v.push_back(root->val);
            return;
        }

        getpath(root->left, p, v);
        if (v.size() > 0)
        {
            v.push_back(root->val);
            return;
        }

        getpath(root->right, p, v);
        if (v.size() > 0)
        {
            v.push_back(root->val);
            return;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<int> v1, v2;
        getpath(root, p, v1);
        getpath(root, q, v2);

        int ans = -1;
        while (v1.size() && v2.size() && (v1.back() == v2.back()))
        {
            ans = v1.back();
            v1.pop_back(), v2.pop_back();
        }

        return new TreeNode(ans);
    }
};
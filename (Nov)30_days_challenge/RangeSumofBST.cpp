/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3532/
*/

#include <iostream>
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        TreeNode *curr = root, *pre = NULL;
        while (curr)
        {
            if (curr->left)
            {
                pre = curr->left;
                while (pre->right)
                    pre = pre->right;
                TreeNode *temp = curr;
                curr = curr->left;
                temp->left = NULL;
                pre->right = temp;
            }
            else
            {
                if (curr->val >= low && curr->val <= high)
                    ans += curr->val;
                curr = curr->right;
            }
        }
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    void inorder(TreeNode *root, int &ans, int low, int high)
    {
        if (!root)
            return;
        if (root->val > low)
            inorder(root->left, ans, low, high);
        if (root->val >= low && root->val <= high)
            ans += root->val;
        if (root->val < high)
            inorder(root->right, ans, low, high);
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        inorder(root, ans, low, high);
        return ans;
    }
};
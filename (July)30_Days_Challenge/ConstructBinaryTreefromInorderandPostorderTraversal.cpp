/*
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution
{
    TreeNode *helper(vector<int> &in, int inl, int inr, vector<int> &po, int pol, int por)
    {
        if (inl > inr || pol > por)
            return NULL;

        TreeNode *node = new TreeNode(po[por]);
        int i;
        for (i = inl; i <= inr; i++)
            if (in[i] == po[por])
                break;

        if (i == inr + 1)
            return NULL;

        node->left = helper(in, inl, i - 1, po, pol, pol - inl + i - 1);
        node->right = helper(in, i + 1, inr, po, pol - inl + i, por - 1);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
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
    // int position = 0;
    TreeNode *helper(vector<int> &preorder, int pos1, int pos2)
    {
        if (pos1 > pos2)
            return NULL;
        if (pos1 == pos2)
        {
            return new TreeNode(preorder[pos1]);
        }

        int left_pos1 = pos1+1;
        int right_pos1 = pos1;
        while(right_pos1 <= pos2 && preorder[right_pos1] <= preorder[pos1])
        {
            right_pos1++;
        }
        
        
        TreeNode* root = new TreeNode(preorder[pos1]);
        root->left = helper(preorder, left_pos1, right_pos1-1);
        root->right = helper(preorder, right_pos1, pos2);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int pos1 = 0;
        int pos2 = preorder.size() - 1;
        return helper(preorder, pos1, pos2);
    }
};
// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

// Note:

// 1 <= preorder.length <= 100
// The values of preorder are distinct.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    // private:
    //     TreeNode* helper(vector<int>& preorder, int* index, int key, int min, int max, int size)
    //     {
    //         if(*index >= size) return NULL;

    //         TreeNode* root = NULL;

    //         if(key > min && key < max)
    //         {
    //             root = new TreeNode(key);
    //             *index = *index + 1;

    //             if(*index < size)
    //             {
    //                 root->left = helper(preorder, index, preorder.at(*index), min, key, size);
    //                 root->right = helper(preorder, index, preorder.at(*index), key, max, size);
    //             }
    //         }
    //         return root;
    //     }

public:
    int index = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int key = INT_MAX)
    {
        // int index = 0;
        // int size = preorder.size();
        // int key = preorder.at(0);
        // return helper(preorder, &index, key, INT_MIN, INT_MAX, size);
        if (index >= preorder.size() || preorder[index] > key)
            return NULL;
        TreeNode *root = new TreeNode(preorder[index]);
        index++;
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, key);
        return root;
    }
};

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

#include <iostream>
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
 
class Solution {
    int i = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return -1;
        int left = kthSmallest(root->left, k);
        if(left != -1)
            return left;
        i++;
        if(i == k)
            return root->val;
        int right = kthSmallest(root->right, k);
        return right;
    }
};
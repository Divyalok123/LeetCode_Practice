//invert a binary tree

#include <iostream>
#include <vector>
#include <algorithm>
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

//better way
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left== NULL && root->right == NULL)) return root;
        
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }
};

//first try
class Solution {
public:
    void solve(TreeNode* root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        solve(root->left);
        solve(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left== NULL && root->right == NULL)) return root;
        
        solve(root);
        return root;

    }
};
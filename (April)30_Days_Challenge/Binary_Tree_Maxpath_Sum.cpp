// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

#include <iostream>
#include <algorithm>
using namespace std;



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
    int helper(TreeNode* root, int& maxval)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = 0, right = 0;
        left = helper(root->left, maxval);
        right = helper(root->right, maxval);
        
        int max1 = max(root->val, root->val + max(left, right));
        maxval = max(maxval, max(root->val + left + right, max1 ));
        
        return max1;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxval = INT_MIN;
        helper(root, maxval);
        return maxval;
    }
};

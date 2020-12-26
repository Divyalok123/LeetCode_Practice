/*
https://leetcode.com/problems/validate-binary-search-tree/
*/

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

/* Solution 1 */
#define ll long long
class Solution {
public:
    bool helper(TreeNode* root, ll forleft, ll forright) {
        if(!root)
            return true;
        
        if(root->val <= forleft || root->val >= forright)
            return false;
        
        return helper(root->left, forleft, root->val) && helper(root->right, root->val, forright);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
/*
https://leetcode.com/problems/zigzag-conversion/
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* root, int& ans, int p, int g) {
        int v = root->val;
        if(!(g&1)) ans+=v;
        
        if(root->left) helper(root->left, ans, v, p);
        if(root->right) helper(root->right, ans, v, p);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        helper(root, ans, 1, 1);
        return ans;
    }
};
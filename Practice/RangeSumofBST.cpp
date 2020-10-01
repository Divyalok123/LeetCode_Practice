/*
https://leetcode.com/problems/range-sum-of-bst/
*/

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
public:
    void dfs(TreeNode* root, int l, int r, int& sum)
    {
        if(!root)
            return;
        
        if(root->val >= l && root->val <= r)
            sum += root->val;
        dfs(root->left, l, r, sum);
        dfs(root->right, l, r, sum);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        int sum = 0;
        dfs(root, L, R, sum);
        return sum;
    }
};
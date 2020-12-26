/*
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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
    int helper(TreeNode* root, int deep, int& fdeep, TreeNode*& ans) {
        if(fdeep < deep) fdeep = deep;
        
        if(!root) return deep;        
        int l = helper(root->left, deep+1, fdeep, ans);
        int r = helper(root->right, deep+1, fdeep, ans);
        
        if(l == r && r == fdeep)
            ans = root;
        return l > r ? l : r;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = NULL;
        int fdeep = 0;
        helper(root, 0, fdeep, ans);
        return ans;
    }
};
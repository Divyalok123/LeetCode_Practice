/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3568/
*/

#include <iostream>
#include <algorithm>
#include <climits>
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
public:
    bool helper(TreeNode* root, long long left, long long right) {
        //if root is null
        if(!root) return true;
        
        //if root's value is less than left and greater than right
        if(root->val < left && root->val > right)
            return helper(root->left, root->val, right) 
                && helper(root->right, left, root->val);
        
        //else return false
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root, LLONG_MAX, LLONG_MIN);
    }
};
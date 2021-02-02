/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3626/
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 2 (Simplified)
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        
        if(root->val < low) 
            return trimBST(root->right, low, high);
        
        else if(root->val > high) 
            return trimBST(root->left, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

// Solution 1
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high, TreeNode* prev = NULL) {
        if(!root) return NULL;
        if(root->val < low) {
            return trimBST(root->right, low, high, prev);
        } else if(root->val > high) {
            return trimBST(root->left, low, high, prev);
        } else if(root->val == low) {
            root->left = NULL;
            if(prev && prev->val < root->val)
                prev = root;                
        } else if(root->val == high) {
            root->right = NULL;
            if(prev && prev->val > root->val)
                prev = root;
        }
        
        if(root) root->left = trimBST(root->left, low, high, root);
        if(root) root->right = trimBST(root->right, low, high, root);
        return root;
    }
};
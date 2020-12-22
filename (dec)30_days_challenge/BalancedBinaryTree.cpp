/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3577/
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

class Solution {
public:

    pair<int, bool> helper(TreeNode* root) {
        if(!root) return {0, 1};
        pair<int, bool> left = helper(root->left);
        pair<int, bool> right = helper(root->right);
        
        int h = max(left.first, right.first) + 1; 
        if(!left.second || !right.second || abs(left.first-right.first) > 1)
            return {h, 0};
        return {h, 1};
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root).second;
    }
};
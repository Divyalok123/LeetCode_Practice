/*
https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3551/
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    int dfs(TreeNode* root, int v) {
        if(!root) return v;
        return max(dfs(root->left, v+1), dfs(root->right, v+1));
    }    
    
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};
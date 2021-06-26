/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    
    void dfs(TreeNode* root, int MAX, int& count) {
        if(!root) return;
        
        if(root->val >= MAX) {
            MAX = root->val;
            count++;
        }
        
        dfs(root->left, MAX, count);
        dfs(root->right, MAX, count);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, -100000, count);
        return count;
    }
};
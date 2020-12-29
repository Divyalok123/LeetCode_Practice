/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/573/week-5-december-29th-december-31st/3585/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper(TreeNode* root, int c, int& ans) {
        if(!root) return;
        
        c ^= (1 << root->val);
        if(!root->left && !root->right) {
            if((c & (c-1)) == 0) ans++;
            return;
        }
        
        helper(root->left, c, ans);
        helper(root->right, c, ans);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};
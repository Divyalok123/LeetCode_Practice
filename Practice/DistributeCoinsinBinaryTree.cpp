/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/
*/

#include <iostream>
#include <algorithm>
#include <vector>
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
    int ans;
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0,0};
        
        auto[reml, extral] = dfs(root->left);
        auto[remr, extrar] = dfs(root->right);
        ans += reml + remr + extral + extrar;
        
        int rem = 0, extra = 0;
        
        if(root->val >= 1) extra = root->val-1;
        else rem = 1;
        
        if(reml == 0 && remr == 0)
            extra += extral + extrar;
        else if(reml == 0) 
            rem += remr, extra += extral;
        else if(remr == 0) 
            rem += reml, extra += extrar;
        else 
            rem += reml + remr;
        
        if(rem >= extra) rem-=extra, extra = 0; 
        else extra-=rem, rem = 0;
        
        return {rem, extra};
    }
    
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
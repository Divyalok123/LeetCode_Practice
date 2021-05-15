/*
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// solution 2
#pragma GCC optimize("Ofast")
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution {
public:
    int n;
    vector<array<int,2>> v;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        root->val = n++;
        dfs(root->left);
        dfs(root->right);
    }
    
    void helper(TreeNode* root) {
        if(!root)
            return;
        
        helper(root->left);
        helper(root->right);
        
        if(root->left)
            v[root->val][0] = 1 + v[root->left->val][1];
        
        if(root->right)
            v[root->val][1] = 1 + v[root->right->val][0];
    }
    
    int longestZigZag(TreeNode* root) {
        n = 0;
        dfs(root);
        
        v.resize(n);
        helper(root);
        
        int fans = 0;
        for(auto& i: v) {
            fans = max(fans, i[0]);
            fans = max(fans, i[1]);
        }
        
        return fans;
    }
};

// solution 1
class Solution {
public:
    
    unordered_map<TreeNode*, array<int, 2>> ans;
    array<int, 2> helper(TreeNode* root) {
        if(!root)
            return {-1, -1};
        
        array<int, 2> left = helper(root->left);
        array<int, 2> right = helper(root->right);
        
        return ans[root] = {1 + left[1], 1 + right[0]};
    }
    
    int longestZigZag(TreeNode* root) {
        helper(root);
        int fans = 0;
        for(auto& i: ans) {
            fans = max(fans, i.second[0]);
            fans = max(fans, i.second[1]);
        }
        
        return fans;
    }
};
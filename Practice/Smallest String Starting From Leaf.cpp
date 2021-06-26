/*
https://leetcode.com/problems/smallest-string-starting-from-leaf/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    
    void dfs(TreeNode* root, string& curr, string& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            curr.push_back('a' + root->val);
            reverse(curr.begin(), curr.end());
            if(curr < ans)
                ans = curr;
            reverse(curr.begin(), curr.end());
            curr.pop_back();
            return;
        }
        
        curr.push_back('a' + root->val);
        if(root->left)
            dfs(root->left, curr, ans);
        if(root->right)
            dfs(root->right, curr, ans);
        curr.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "|";
        string curr;
        dfs(root, curr, ans);
        return ans;
    }
};
/*
https://leetcode.com/problems/unique-binary-search-trees-ii/
*/

#include <iostream>
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

//  Little Improvement
class Solution {
public:
    vector<TreeNode*> makeTree(int i, int j) {
        if(i > j)
            return {NULL};
        
        if(i == j) {
            TreeNode* root = new TreeNode(i);
            return {root};
        }
        
        vector<TreeNode*> ans;
        for(int k = i; k <= j; k++) {
            auto left = makeTree(i, k-1);
            auto right = makeTree(k+1, j);
            
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return makeTree(1, n);
    }
};

// Recursion
class Solution {
public:
    vector<TreeNode*> makeTree(int i, int j) {
        if(i > j) {
            return {};
        }
        
        if(i == j) {
            TreeNode* root = new TreeNode(i);
            return {root};
        }
        
        vector<TreeNode*> ans;
        for(int k = i; k <= j; k++) {
            auto left = makeTree(i, k-1);
            auto right = makeTree(k+1, j);
            
            if(left.size() && right.size()) {
                for(auto l: left) {
                    for(auto r: right) {
                        TreeNode* root = new TreeNode(k);
                        root->left = l;
                        root->right = r;
                        ans.push_back(root);
                    }
                }
            } else if(left.size()) {
                for(auto l: left) {
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    ans.push_back(root);
                }
            } else {
                for(auto r: right) {
                    TreeNode* root = new TreeNode(k);
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return makeTree(1, n);
    }
};
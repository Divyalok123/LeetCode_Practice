/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// improving to O(1) space iterative
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        while(root) {
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right)
                    temp = temp->right;
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
            } 
                
            root = root->right;
        }
    }
};

// O(N) space iterative
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        stack<TreeNode*> st;
        while(root) {
            if(root->right)
                st.push(root->right);
            
            root->right = root->left;
            root->left = NULL;
            
            if(!root->right && st.size())
            {
                root->right = st.top();
                st.pop();
            }
            
            root = root->right;
        }
    }
};

// smarter recursive 
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// simple recursive solution
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        flatten(root->right);

        if(!root->left) return;

        TreeNode* temp = root->left;
        while(temp && temp->right)
            temp = temp->right;

        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
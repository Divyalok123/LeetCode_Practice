/*
https://leetcode.com/problems/balance-a-binary-search-tree/
*/

#include <iostream>
#include <vector>
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

// DSW Algo - O(n) time & O(1) space


// inorder + preorder - O(n) time & space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& store) {
        if(!root) return;
        
        inorder(root->left, store);
        store.push_back(root->val);
        inorder(root->right, store);
    }
    
    TreeNode* makebst(vector<int>& store, int i, int j) {
        if(i > j) return NULL;
        
        int m = i + (j-i)/2;
        
        TreeNode* root = new TreeNode(store[m]);
        root->left = makebst(store, i, m-1);
        root->right = makebst(store, m+1, j);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> store;
        inorder(root, store);
        int i = 0, j = store.size()-1;
        return makebst(store, i, j);
    }
};
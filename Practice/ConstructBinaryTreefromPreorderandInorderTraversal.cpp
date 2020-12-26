/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Solution 3 O(1) space */
class Solution {
public:
    
    TreeNode* helper(int stopnode, vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        if(inorder.back() == stopnode) {
            inorder.pop_back();
            return NULL;
        }
        
        TreeNode* tempnode = new TreeNode(preorder.back());
        preorder.pop_back();
        
        tempnode->left = helper(tempnode->val, preorder, inorder);
        tempnode->right = helper(stopnode, preorder, inorder);
        return tempnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        reverse(preorder.begin(), preorder.end());
        reverse(inorder.begin(), inorder.end());
        return helper(INT_MIN, preorder, inorder);
    }
};

/* Solution 2 (iterative)*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        TreeNode* temp, *ans = new TreeNode(preorder[0]);
        temp = ans;
        stack<TreeNode*> s;
        s.push(temp);
        int i = 1, j = 0;
        bool f = 0;
        while(i < n) {
            if(!s.empty() && (s.top()->val == inorder[j])) {
                f = 1;
                temp = s.top();
                s.pop();
                j++;
            } else {
                if(f == 1) {
                    f = 0;
                    temp->right = new TreeNode(preorder[i++]);
                    temp = temp->right;
                } else {
                    temp->left = new TreeNode(preorder[i++]);
                    temp = temp->left;
                }
                s.push(temp);
            }
        }
        
        return ans;
    }
};

/* Solution 1 (recursive)*/
class Solution {
public:
    unordered_map<int, int> umap;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prei, int prej, int ini, int inj) {
        if(prei > prej || ini > inj)
            return NULL;
        
        TreeNode* newnode = new TreeNode(preorder[prei]);
        int i = umap[preorder[prei]]-1;;
        
        int lprej = prei + i- ini;
        newnode->left = build(preorder, inorder, prei+1, lprej, ini, i-1);
        newnode->right = build(preorder, inorder, lprej+1, prej, i+1, inj);
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        
        for(int i = 0; i < n; i++)
            umap[inorder[i]] = i+1;
        
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};
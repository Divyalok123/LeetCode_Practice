// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

#include <iostream>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
    int parentx = -1, parenty = -1; //considering tree will contain distinct elements
    int depthx = -1, depthy = -1;
    
    void search(TreeNode* root, int x, int y, int thisparent, int thisdepth)
    {
        if(root==NULL) return;
        
        if(root->val == x)
        {
            parentx = thisparent;
            depthx = thisdepth;
        }
        
        if(root->val == y)
        {
            parenty = thisparent;
            depthy = thisdepth;
        }
        
        search(root->left, x, y, root->val, thisdepth + 1);
        search(root->right, x, y, root->val, thisdepth + 1);
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
           return false;
        search(root, x, y, 0, -1);
        cout << parentx << " " << parenty << endl;
        cout << depthx << " " << depthy << endl;
        return parentx != parenty && depthx == depthy && depthx != -1 && depthy != -1;                   
    }
};
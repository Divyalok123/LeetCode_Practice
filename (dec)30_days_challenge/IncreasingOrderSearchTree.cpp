/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3553/
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

/* Solution 3 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if(!root) return tail;
        TreeNode* left = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return left;
    }
};

/* Solution 2 */
class Solution {
public:
    TreeNode* left, *last;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;

        increasingBST(root->left);
        
        if(left) {
            last->right = root;
        } else {
            left = root;
        }
        
        last = root;
        root->left = NULL;
        increasingBST(root->right);
        
        return left;
    }
};

/* Solution 1 */
class Solution {
public:
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;

        TreeNode* left = increasingBST(root->left);
        root->left = NULL;
        
        TreeNode* temp = left;
        while(temp && temp->right)
            temp = temp->right;
        
        if(temp) 
            temp->right = root;
        
        root->right = increasingBST(root->right);
        return left ? left : root;
    }
};
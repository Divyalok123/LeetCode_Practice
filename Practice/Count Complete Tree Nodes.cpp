/*
https://leetcode.com/problems/count-complete-tree-nodes/
*/

#include <iostream>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        TreeNode* temp = root;        
        int leftheight = 0, rightheight = 0;
        
        while(temp) temp = temp->left, leftheight++;
        
        temp  = root;
        
        while(temp) temp = temp->right, rightheight++;
        
        if(leftheight == rightheight) return (1 << leftheight) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);        
    }
};
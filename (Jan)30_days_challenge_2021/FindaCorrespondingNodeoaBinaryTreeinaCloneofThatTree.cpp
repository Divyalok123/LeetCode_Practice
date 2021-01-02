/*
https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3590/
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        
        if(original == target) 
            return cloned;
        
        TreeNode* l = getTargetCopy(original->left, cloned->left, target);
        if(l) return l;
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};
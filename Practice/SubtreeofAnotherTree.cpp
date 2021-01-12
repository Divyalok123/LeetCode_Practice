/*
https://leetcode.com/problems/subtree-of-another-tree/
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool check(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        
        if(s->val != t->val) return 0;
        return check(s->left, t->left) && check(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return 1;
        if(!s || !t) return 0;
        
        if(s->val == t->val) if(check(s, t)) return 1;
        if(s->left) if(isSubtree(s->left, t)) return 1;
        if(s->right) if(isSubtree(s->right, t)) return 1;
        return 0;
        // return checkr || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
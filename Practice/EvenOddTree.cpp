/*
https://leetcode.com/problems/even-odd-tree/
*/

#include <iostream>
#include <algorithm>
#include <queue>
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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int i = 0;
        while(q.size()) {
            int sz = q.size(), prev;
            if(i&1) prev = INT_MAX;
            else prev = -1;
            
            for(int j = 0; j < sz; j++) {
                TreeNode* f = q.front();
                q.pop();
                
                if(i&1) {
                    if((f->val)&1 || f->val >= prev) 
                        return false;
                } else { 
                    if(!((f->val)&1) || f->val <= prev) 
                        return false;
                }
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
                prev = f->val;
            }
            i++;
        }
        
        return true;
    }
};
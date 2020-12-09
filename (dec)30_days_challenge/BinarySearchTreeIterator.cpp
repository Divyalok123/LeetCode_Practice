/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3560/
*/

#include <iostream>
#include <stack>
using namespace std;

class BSTIterator {
    stack<TreeNode* > s;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        
        TreeNode* temp = ans->right;
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        
        return ans->val;
    }
    
    bool hasNext() {
        return s.size();         
    }
};
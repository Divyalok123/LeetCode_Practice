/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3630/
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// Solution 1

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                if(i == 0) 
                    ans.push_back(t->val);
                
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
            }
        }
        
        return ans;
    }
};
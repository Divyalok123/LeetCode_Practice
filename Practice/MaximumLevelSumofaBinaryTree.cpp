/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
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
    int maxLevelSum(TreeNode* root) {
        using ll = long long;
        ll maxval = INT_MIN;
        int minlev = -1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lev = 1;
        ll sum = 0;
        while(q.size()) {
            int sz = q.size();
            sum = 0;
            while(sz--) {
                TreeNode* f = q.front();
                q.pop();
                
                sum += (ll)(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
            if(sum > maxval) {
                maxval = sum;
                minlev = lev;
            }
            
            lev++;
        }
        
        return minlev;
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3541/
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Solution 2 */
class Solution {
public:
    pii helper(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        pii l1 = helper(root->left);
        pii r1 = helper(root->right);
        int v = l1.ss+r1.ss;
        return {v, max(root->val+l1.ff+r1.ff, v)};
    }
    
    int rob(TreeNode* root) {
        pii ans = helper(root);
        return max(ans.ff, ans.ss);
    }
};

/* Solution 1 */
class Solution {
public:
    pii helper(TreeNode* root) {
        if(!root)
            return {0, 0};
        
        pii l1 = helper(root->left);
        pii r1 = helper(root->right);
        return {max(l1.ff, l1.ss) + max(r1.ff, r1.ss), root->val + l1.ff + r1.ff};
    }
    
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        pii ans = helper(root);
        return max(ans.ff, ans.ss);
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3525/
*/

#include <iostream>
#include <algorithm>
using namespace std;

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
    void helper(TreeNode* root, int& ans, int minval, int maxval) {
        if(!root) {
            ans = max(ans, maxval-minval);
            return;
        }   
        
        maxval = max(root->val, maxval);
        minval = min(root->val, minval);
        
        helper(root->left, ans, minval, maxval);
        helper(root->right, ans, minval, maxval);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        helper(root, ans, INT_MAX, INT_MIN);
        return ans;
    }
};

/* Solution 1 */
class thepair
{
public:
    int minval, maxval;
    thepair() : minval(1100000), maxval(-1100000) {}
    thepair(int a, int b) : minval(a), maxval(b) {}
};

class Solution
{
public:
    thepair helper(TreeNode *root, int &ans)
    {
        thepair thisans;
        if (!root->left && !root->right)
        {
            thisans.minval = root->val;
            thisans.maxval = root->val;
        }
        else if (!root->left)
        {
            thepair right = helper(root->right, ans);
            ans = max(ans, max(abs(root->val - right.minval), abs(root->val - right.maxval)));
            thisans.minval = min(root->val, right.minval);
            thisans.maxval = max(root->val, right.maxval);
        }
        else if (!root->right)
        {
            thepair left = helper(root->left, ans);
            ans = max(ans, max(abs(root->val - left.minval), abs(root->val - left.maxval)));
            thisans.minval = min(root->val, left.minval);
            thisans.maxval = max(root->val, left.maxval);
        }
        else
        {
            thepair left = helper(root->left, ans);
            thepair right = helper(root->right, ans);
            int thismin = min(left.minval, right.minval);
            int thismax = max(left.maxval, right.maxval);
            ans = max(ans, max(abs(root->val - thismin), abs(root->val - thismax)));
            thisans.minval = min(root->val, thismin);
            thisans.maxval = max(root->val, thismax);
        }
        return thisans;
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
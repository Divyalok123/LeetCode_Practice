/*
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
    For example:
    Given binary tree [3,9,20,null,null,15,7],
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> output;
        if (!root)
            return output;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;

        s1.push(root);
        int i = 1;
        while (!s1.empty() || !s2.empty())
        {
            TreeNode *t;
            vector<int> v;
            if (i == 1)
            {
                while (!s1.empty())
                {
                    t = s1.top(), s1.pop();
                    v.push_back(t->val);
                    if (t->left)
                        s2.push(t->left);
                    if (t->right)
                        s2.push(t->right);
                }
                i = 0;
            }
            else
            {
                while (!s2.empty())
                {
                    t = s2.top(), s2.pop();
                    v.push_back(t->val);
                    if (t->right)
                        s1.push(t->right);
                    if (t->left)
                        s1.push(t->left);
                }
                i = 1;
            }
            output.push_back(v);
        }
        return output;
    }
};
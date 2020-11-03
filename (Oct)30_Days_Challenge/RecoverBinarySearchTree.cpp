/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3514/
*/

#include <iostream>
#include <algorithm>
#include <vector>
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

/* Time: O(n), Space: O(1) */
class Solution
{
public:
    TreeNode *pre = NULL, *f = NULL, *s = NULL;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            if (pre && pre->val > root->val)
            {
                if (!f)
                    f = pre;
                s = root;
            }
            pre = root;
            dfs(root->right);
        }
    }

    void recoverTree(TreeNode *root)
    {
        dfs(root);
        int temp = f->val;
        f->val = s->val;
        s->val = temp;
    }
};

/* Time: O(n), Space: O(n) */
class Solution
{
public:
    vector<TreeNode *> v;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        int a, b, n = v.size();

        for (int i = n - 1; i >= 1; i--)
            if (v[i]->val < v[i - 1]->val)
            {
                a = i;
                break;
            }

        for (int i = 0; i < n - 1; i++)
            if (v[i]->val > v[i + 1]->val)
            {
                b = i;
                break;
            }

        v[a]->val ^= v[b]->val ^= v[a]->val ^= v[b]->val;
    }
};

/* Time: O(nlogn), Space: O(n) */
class Solution
{
public:
    vector<int> v;
    int i = 0;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    void sdfs(TreeNode *root)
    {
        if (root)
        {
            sdfs(root->left);
            root->val = v[i++];
            sdfs(root->right);
        }
    }

    void recoverTree(TreeNode *root)
    {
        dfs(root);
        sort(v.begin(), v.end());
        sdfs(root);
    }
};
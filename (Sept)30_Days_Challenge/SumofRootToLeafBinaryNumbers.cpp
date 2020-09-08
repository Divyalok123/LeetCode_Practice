/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3453/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//solution 2


//solution 1
class Solution
{
    int resolve(string &s)
    {
        // cout << "s: " << s << endl;
        int n = s.size(), ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                ans += pow(2, n - i - 1);
        }
        // cout << "ans: " << ans << endl;
        return ans;
    }

public:
    void dfs(TreeNode *root, string s, int &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            s += to_string(root->val);
            ans += resolve(s);
            return;
        }

        s += to_string(root->val);
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val == 1;

        int ans = 0;
        dfs(root, "", ans);
        return ans;
    }
};
#include <iostream>
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

class Solution
{
    void go(TreeNode *root, int &sum, char c = 'n')
    {
        if (!root)
            return;
        if (!root->left && !root->right && c == 'l')
            sum += root->val;
        go(root->left, sum, 'l');
        go(root->right, sum, 'n');
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        go(root, sum);
        return sum;
    }
};
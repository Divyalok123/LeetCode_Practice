/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go
downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to
1,000,000.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
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

    void dfs(TreeNode* root, int sum, int curr, int& t) {
        if (curr == sum)
            t = t+1;

        if (root == NULL)
            return;

        if (root->left) dfs(root->left, sum, curr+root->left->val, t);
        if (root->right) dfs(root->right, sum, curr+root->right->val, t);
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val == sum;

        int from_left = pathSum(root->left, sum);
        int from_right = pathSum(root->right, sum);

        int from_root = 0;
        dfs(root, sum, root->val, from_root);
        return from_left+from_right+from_root;
    }
};
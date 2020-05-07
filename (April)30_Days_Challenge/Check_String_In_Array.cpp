/* 
Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string 
is a valid sequence in such biinary tree.
We get the given string from the concatenation of an array of integers arr, and the concatenation of all values of
the nodes along a path results in a sequence in the given binary tree.
*/

#include <iostream>
#include <vector>
using namespace std;

//Provided by LeetCode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode *root, vector<int> &arr, int index)
{
    int n = arr.size();
    if (root == NULL || index >= n)
        return false;

    if (root->left == NULL && root->left == NULL)
    {
        return index == n-1;
    }

    return (root->val == arr[index]) && (helper(root->left, arr, index + 1) || helper(root->right, arr, index + 1);
}

bool given(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return false;
    return helper(root, arr, 0);
}
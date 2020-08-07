/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
*/

#include <iostream>
#include <vector>
#include <map>
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
    map<int, vector<pair<int, int>>> _m;
    
    void helper(TreeNode* root, int i, int j) {
        if(root == NULL)
            return;
    
        _m[i].push_back({root->val, j});
        helper(root->left, i-1, j-1);
        helper(root->right, i+1, j-1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        vector<int> t;
        vector<vector<int>> output;
        for(auto a: _m) {
            sort(a.second.begin(), a.second.end(), [&](pair<int, int>& x, pair<int, int>& y){
                return x.second != y.second ? x.second > y.second : x.first < y.first;
            });
            for(auto p: a.second) {
                t.push_back(p.first);
            }
            output.push_back(t);
            t.clear();
        }
        
        return output;
    }
};
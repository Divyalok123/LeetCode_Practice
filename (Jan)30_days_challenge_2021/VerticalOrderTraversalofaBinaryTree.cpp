/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3621/
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
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
    map<int, map<int, multiset<int>>> m;
    
    void dfs(TreeNode* root, int x, int y) {
        if(!root) return;
        m[x][y].insert(root->val);
        dfs(root->left, x-1, y+1);
        dfs(root->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, 0);
        
        for(auto& i: m) {
            vector<int> v;
            for(auto& j: i.second) {
                for(auto& k: j.second) {
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};
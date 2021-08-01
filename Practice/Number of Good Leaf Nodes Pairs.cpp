/*
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
*/

#include <iostream>
#include <vector>
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

// dfs: passing every leaf length
class Solution {
public:
    vector<int> dfs(TreeNode* root, int& ans, int dist) {
        if(!root) return {};
        
        if(!root->left && !root->right)
            return {1};
        
        vector<int> left = dfs(root->left, ans, dist);
        vector<int> right = dfs(root->right, ans, dist);
        
        for(int& i: left) {
            for(int& j: right) {
                if(i + j <= dist)
                    ans++;
            }
        }
        
        int n = left.size(), m = right.size();
        vector<int> fvec;
        fvec.reserve(n + m);
       
        for(int& i: left) 
            if(i + 1 < dist) fvec.emplace_back(i+1);
        
        for(int& i: right) 
            if(i + 1 < dist) fvec.emplace_back(i+1);
        
        return fvec;
    }
    
    
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        if(!root->left && !root->right) return ans;
        
        dfs(root, ans, distance);
        return ans;
    }
};
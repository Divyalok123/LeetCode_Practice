/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3449/
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
    vector<int> ans;
public:
    void dfs(TreeNode* root, vector<int>& v)
    {
        if(!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    
    void merge(vector<int>& v1, vector<int>& v2)
    {
        int n1 = v1.size(), n2 = v2.size();
        if(n1 == 0) { ans = v2; return; }
        if(n2 == 0) { ans = v1; return; }
        
        ans.resize(n1+n2);
        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2)
        {
            if(v1[i] < v2[j]) 
                ans[k++] = v1[i++];
            else 
                ans[k++] = v2[j++];
        }
        
        while(i < n1)
            ans[k++] = v1[i++];
        
        while(j < n2)
            ans[k++] = v2[j++];
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        merge(v1, v2);
        return ans;
    }
};
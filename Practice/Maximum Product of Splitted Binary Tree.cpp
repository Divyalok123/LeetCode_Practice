/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();

// without modifying the tree
class Solution {
public:
    int MOD;
    
    void getsum(TreeNode* root, long long& sum) {
        if(!root) return;
        
        sum += root->val;
        if(root->left) getsum(root->left, sum);
        if(root->right) getsum(root->right, sum);
    }
    
    long long getans(long long& ans, TreeNode* root, long long total) {
        if(!root) return 0;
        
        long long left = 0, right = 0;
        if(root->left)
            left = getans(ans, root->left, total);
        if(root->right)
            right = getans(ans, root->right, total);
        
        ans = max(ans, left*(total-left));
        ans = max(ans, right*(total-right));
        return left + right + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        MOD = 1000000007;
        long long ans = 0, total = 0;
        getsum(root, total);
        getans(ans, root, total);
        return ans%MOD;
    }
};

// simple dfs
class Solution {
public:
    int MOD;
    int getsums(TreeNode* root) {
        if(!root) return 0;
        
        int l = getsums(root->left);
        int r = getsums(root->right);
        
        return root->val += l+r;
    }
    
    void getans(long long& ans, TreeNode* root, long long total) {
        if(!root) return;
        
        if(root->left) {
            ans = max(ans, root->left->val*(total-root->left->val));
            getans(ans, root->left, total);
        }
        
        if(root->right) {
            ans = max(ans, root->right->val*(total-root->right->val));
            getans(ans, root->right, total);
        }
    }
    
    int maxProduct(TreeNode* root) {
        MOD = 1000000007;
        getsums(root);

        long long ans = 0, total = root->val;
        getans(ans, root, total);
        return ans%MOD;
    }
};
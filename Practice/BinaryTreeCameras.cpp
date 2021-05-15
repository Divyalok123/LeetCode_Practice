/*
https://leetcode.com/problems/binary-tree-cameras/
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution 2
//0->not watched
//1->watched with camera
//2->watched without camera/not needed

class Solution {
public:
    int count;
    int dfs(TreeNode* root) {
        if(!root) return 2;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l == 0 || r == 0) {
            count++;
            return 1; 
        } else if(l == 1 || r == 1) {
            return 2;
        } else {
            return 0;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        count = 0;
        int val = dfs(root);
        return val == 0 ? ++count : count;
    }
};

// Solution 1
class Solution
{
public:
    tuple<int, int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 900000, 0};

        auto [reml, withl, withoutl] = dfs(root->left);
        auto [remr, withr, withoutr] = dfs(root->right);

        int minl = min(withl, withoutl);
        int minr = min(withr, withoutr);

        return {withoutl + withoutr,
                1 + min(reml, minl) + min(remr, minr),
                min(withl + min(withr, withoutr), withr + min(withl, withoutl))};
    }

    int minCameraCover(TreeNode *root)
    {
        if (!root)
            return 0;

        auto [rem, with, without] = dfs(root);
        return min(with, without);
    }
};
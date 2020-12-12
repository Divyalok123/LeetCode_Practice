/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3563/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 2 */
#define ss second
#define ff first

class Solution {
public:
    using pti = pair<TreeNode*, int>;
    pti helper(TreeNode* root) {
        if(!root) return {nullptr, 0};
        
        pti l = helper(root->left);
        pti r = helper(root->right);
        
        return l.ss == r.ss ? make_pair(root, l.ss+1) 
                            : (l.ss > r.ss ? make_pair(l.ff, l.ss+1) 
                                           : make_pair(r.ff, r.ss+1));
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).ff;
    }
    
};

/* Solution 1 */
class Solution {
public:
    vector<int> v; //since value of every node is unique we can use it
                // else we will need to use hashmap/set or pass height in pairs 
    int height(TreeNode* root) {
        if(!root) return 0;
        
        int& ref = v[root->val];
        if(ref != -1) return ref;
        return ref = 1 + max(height(root->left), height(root->right));
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        if(!v.size()) v.assign(500, -1);
        
        if(!root->left)
            return subtreeWithAllDeepest(root->right);
        else if(!root->right)
            return subtreeWithAllDeepest(root->left);
        
        int hl = height(root->left);
        int hr = height(root->right);
        if(hl == hr) return root;
        return hl < hr ? subtreeWithAllDeepest(root->right) : subtreeWithAllDeepest(root->left);
    }
};
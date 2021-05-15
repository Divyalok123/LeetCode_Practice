/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    
    TreeNode* makeTree(vector<int>& v, int i, int j) {
        if(i > j)
            return NULL;
        
        TreeNode* root;
        if(i == j)
            return root = new TreeNode(v[i]);
        
        int len = j-i+1;
        int wetake = len/2;
        
        root = new TreeNode(v[wetake]);
        root->left = makeTree(v, i, wetake-1);
        root->right = makeTree(v, wetake+1, j);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) 
            return NULL;
        
        vector<int> v;
        ListNode* temp = head;
        while(temp) 
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int len = v.size();
        return makeTree(v, 0, len-1);        
    }
};

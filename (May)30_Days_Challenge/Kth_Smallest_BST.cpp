// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

#include <iostream>
#include <queue>
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
 
//The best one (for the follow up question)
class nodewithcount {
    public:
    int val;
    int lcount;
    nodewithcount* left;
    nodewithcount* right;
    nodewithcount(int x): left(NULL), right(NULL) {
        this->val = x;
        this->lcount = 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        nodewithcount* rootwithcount = createNewBstWithCount(root);
        return kthSmallestBetter(rootwithcount, k);
    }
    
    int kthSmallestBetter(nodewithcount* rootwithcount, int k)
    {
        while(rootwithcount != NULL)
        {
            if(k == rootwithcount->lcount+1)
            {
                return rootwithcount->val;
            }
            else if(k <= rootwithcount->lcount)
            {
                rootwithcount = rootwithcount->left;
            }
            else
            {
                k -= (rootwithcount->lcount+1);
                rootwithcount = rootwithcount->right;
            }
        }
        return -1;
    }
    
    nodewithcount* createNewBstWithCount(TreeNode* root)
    {
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        nodewithcount* rootwithcount = NULL;
        while(!myqueue.empty())
        {
            TreeNode* temp = myqueue.front();
            myqueue.pop();
            nodewithcount* node = new nodewithcount(temp->val);
            rootwithcount = insertBstNode(rootwithcount, node);
            if(temp->left != NULL)
                myqueue.push(temp->left);
            if(temp->right != NULL)
                myqueue.push(temp->right);
        }
        return rootwithcount;
    }
    
    nodewithcount* insertBstNode(nodewithcount* rootwithcount, nodewithcount* node)
    {
        nodewithcount* curr = rootwithcount;
        nodewithcount* parent = rootwithcount;
        while(curr != NULL)
        {
            parent = curr;
            if(node->val < curr->val)
            {
                curr->lcount++;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        
        if(rootwithcount == NULL)
            rootwithcount = node;
        else if(node->val < parent->val)
            parent->left = node;
        else
            parent->right = node;
        return rootwithcount;
    }
};

//Try2 
class Solution {
    int count(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + count(root->left) + count(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int numnodes = count(root->left);
        if(numnodes == k-1)
        {
            return root->val;
        }
        else if(numnodes > k-1)
        {
            return kthSmallest(root->left, k);
        }
        else 
            return kthSmallest(root->right, k - numnodes-1);
    }
};

//Try 1
class Solution {
    int i = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return -1;
        int left = kthSmallest(root->left, k);
        if(left != -1)
            return left;
        i++;
        if(i == k)
            return root->val;
        int right = kthSmallest(root->right, k);
        return right;
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3529/
*/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/* Solution 2 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        int s;
        Node* curr;
        
        while(q.size()) {
            s = q.size();
            for(int i = 0; i < s; i++) {
                curr = q.front();
                q.pop();
                
                if(i != s-1)
                    curr->next = q.front();
                
                if(curr->left) {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};

/* Solution 1 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        // if(!root->left && !root->right)
            // return root;
        
        Node* left = connect(root->left);
        Node* right = connect(root->right);
        // left->next = right;
        
        // left = left->right;
        // right = right->left;
        while(left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        
        return root;
    }
};
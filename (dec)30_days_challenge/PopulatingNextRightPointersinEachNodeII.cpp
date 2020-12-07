/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3556/
*/

#include <iostream>
#include <algorithm>
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

/* Solution 3 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        Node* ans = root;
        Node* dummy = new Node(0), *temp;
        
        while(root) {
            temp = dummy;
            while(root) {
                if(root->left) {
                    temp->next = root->left;
                    temp = temp->next;
                } 
                
                if(root->right) {
                    temp->next = root->right;
                    temp = temp->next;
                }
                
                root = root->next;
            }
            
            root = dummy->next;
            dummy->next = NULL;
        }
        
        return ans;
        
    }
};

/* Solution 2 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        Node* temp, *prev;
        queue<Node*> q;
        q.push(root);
        
        while(q.size()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();
                
                if(i > 0)
                    prev->next = temp;
                
                prev = temp;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return root;
        
    }
};

/* Solution 1 */
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        Node *pre = root;
        Node *cur = NULL;

        while (pre)
        {
            cur = pre;
            while (cur)
            {
                if (cur->left)
                {
                    if (cur->right)
                        cur->left->next = cur->right;
                    else
                    {
                        if (cur->next)
                        {
                            Node *temp = cur->next;
                            while (temp && !temp->left && !temp->right)
                                temp = temp->next;
                            if (temp)
                            {
                                cur->left->next = temp->left ? temp->left : temp->right;
                            }
                        }
                    }
                }

                if (cur->right)
                {
                    if (cur->next)
                    {
                        Node *temp = cur->next;
                        while (temp && !temp->left && !temp->right)
                            temp = temp->next;
                        if (temp)
                            cur->right->next = temp->left ? temp->left : temp->right;
                    }
                }

                cur = cur->next;
            }

            while (pre && !pre->left && !pre->right)
                pre = pre->next;

            if (!pre)
                break;

            pre = pre->left ? pre->left : pre->right;
        }

        return root;
    }
};
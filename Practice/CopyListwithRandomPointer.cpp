/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/* Solution 3 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        Node* temp, *temp2;
        temp = head;
        while(temp) {
            temp2 = new Node(temp->val);
            temp2->next = temp->random;
            temp->random = temp2;
            temp = temp->next;
        }
        
        temp = head;
        while(temp) {
            temp2 = temp->random;
            temp2->random = temp2->next ? temp2->next->random : nullptr;
            temp = temp->next;
        }
        
        Node* ans = head->random;
        temp = head;
        while(temp) {
            temp2 = temp->random;
            temp->random = temp2->next;
            temp2->next = temp->next ? temp->next->random : nullptr;
            temp = temp->next;
        }
        
        return ans;
    }
};

/* Solution 2 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node* iter = head, *temp;
        while(iter) {
            temp = new Node(iter->val);
            temp->next = iter->next;
            iter->next = temp;
            iter = iter->next->next;
        }
        
        iter = head;
        while(iter) {
            if(iter->random)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        iter = head;
        Node* ans = head->next;
        while(iter) {
            temp = iter->next;
            iter->next = temp->next;
            if(temp->next) 
                temp->next = temp->next->next;
            iter = iter->next;
        }
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        unordered_map<Node*, Node*> umap;
        
        Node* iter = head;
        while(iter) {
            umap[iter] = new Node(iter->val);
            iter = iter->next;
        }
        
        iter = head;
        while(iter) {
            umap[iter]->next = umap[iter->next];
            umap[iter]->random = umap[iter->random];
            iter = iter->next;
        }
        
        return umap[head];
    }
};
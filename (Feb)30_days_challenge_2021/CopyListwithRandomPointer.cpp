/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3635/
*/

#include <iostream>
#include <algorithm>
using namespace std;

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead = new Node(0);
        
        Node* temp = head, *ans = newhead;
        while(temp) {
            newhead = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = newhead;
            temp = temp->next->next;
        }
        
        temp = head;
        while(temp) {
            newhead = temp->next;
            if(temp->random) 
                newhead->random = temp->random->next;
            temp = temp->next->next;
        }
        
        temp = head;
        newhead = ans;
        while(temp) {
            newhead->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            newhead = newhead->next;
        }
        
        // cout << "here" << endl;
        return ans->next;
    }
};
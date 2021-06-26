/*
https://leetcode.com/problems/partition-list/
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    void printLL(ListNode* ll) {
        ListNode* temp = ll;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }        
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp1 = NULL, *temp2 = NULL, *temp = head;
        ListNode* head1 = NULL, *head2 = NULL;
        
        while(temp) {
            if(temp->val < x) {
                // cout << "less" << endl;
                if(!temp1) {
                    temp1 = temp;
                    head1 = temp1;
                } else {
                    // cout << "curr temp1: " << temp1->val << endl;
                    temp1->next = temp;
                    temp1 = temp1->next;
                    // cout << "end" << endl;
                }
            } else {
                // cout << "more" << endl;
                if(!temp2) {
                    temp2 = temp;
                    head2 = temp2;
                } else {
                    // cout << "curr temp2: " << temp2->val << endl;
                    temp2->next = temp;
                    temp2 = temp2->next;
                    // cout << "end" << endl;
                }
            }
            temp = temp->next;
        }
        
        if(temp1)
            temp1->next = head2;
        if(temp2)
            temp2->next = NULL;
        
        return head1 ? head1 : head2;
    }
};
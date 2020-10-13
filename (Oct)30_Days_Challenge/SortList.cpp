/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3493/
*/


#include <iostream>
#include <algorithm>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int length;
    int getlength(ListNode* head) {
        ListNode* temp = head;
        int ans = 0;
        while(temp) {
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    
    void print(ListNode* head) {
        ListNode* print = head;
        while(print)
        {
            cout << print->val << " ";
            print = print->next;
        }
        cout << endl;
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) 
    {
        if(!head1 || !head2)
            return !head1 ? head2 : head1;
        
        ListNode* finalans = NULL, *temp = NULL;
        while(head1 && head2) {
            if(head1->val < head2->val) {
                if(!temp) {
                    temp = head1;
                    finalans = temp;
                } else {
                    temp->next = head1;
                    temp = temp->next;
                }
                head1 = head1->next;
            } else {
                if(!temp) {
                    temp = head2;
                    finalans = temp;
                } else {
                    temp->next = head2;
                    temp = temp->next;
                }
                head2 = head2->next;
            }
        }
        
        while(head1) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        
        while(head2) {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
        
        // cout << "printing finalans: " << endl;
        // print(finalans);
        // cout << "printing finished" << endl;
        
        return finalans;
    }
    
    ListNode* sorthelper(ListNode* head) {
        if(!head)
            return NULL;
        int length = getlength(head);
        if(length == 1)
            return head;
        
        int mid = (length-1)/2;
        
        ListNode* head1 = head, *head2 = head, *prev;
        
        prev = NULL;
        head1 = head;
        for(int k = 0; k < mid+1; k++) {
            prev = head1; 
            head1 = head1->next;
        }
        prev->next = NULL;
        
        // cout << "printing head1 and head2" << endl;
        // print(head1);
        // print(head2);
        // cout << "finished!" << endl;
        
        head1 = sorthelper(head1);
        head2 = sorthelper(head2);
        head = merge(head1, head2);
        return head;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        //we can use merge sort
        head = sorthelper(head);
        return head;        
    }
};
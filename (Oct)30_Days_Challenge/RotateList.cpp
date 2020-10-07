/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3486/
*/

#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution 1 */
class Solution {
public:
    
    int getlen(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp)
            len++, temp = temp->next;
        return len;
    } 
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        int length = getlen(head);
        k %= length;
        
        ListNode* temp1 = head;
        ListNode* temp2 = NULL;
        
        k = (length-k)%length;
        
        if(k == 0)
            return head;
        
        while(k-- && temp1) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        
        temp2->next = NULL;
        temp2 = temp1;
        
        while(temp1->next)
            temp1 = temp1->next;
        temp1->next = head;
        
        return temp2;
    }
};
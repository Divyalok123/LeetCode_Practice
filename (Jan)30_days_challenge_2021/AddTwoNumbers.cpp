/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3601/
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1, *prev = NULL;
        int carry = 0;
        while(l1 && l2) {
            int v = l1->val + l2->val + carry;
            carry = v/10;
            v %= 10;
            
            l1->val = v;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(!l1) prev->next = l2;
        else prev->next = l1;
        
        while(l1) {
            int v = l1->val + carry;
            carry = v/10;
            v %= 10;
            
            l1->val = v;
            prev = l1;
            l1 = l1->next;
        }
        
        while(l2) {
            int v = l2->val + carry;
            carry = v/10;
            v %= 10;
            
            l2->val = v;
            prev = l2;
            l2 = l2->next;
        }
        
        if(carry) prev->next = new ListNode(1);
        return ans;
    }
};
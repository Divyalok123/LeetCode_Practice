/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3517/
*/

#include <iostream>
#include <vector>
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

/* Solution 3 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* prev = new ListNode(0), *trav = NULL, *temp1 = head, *temp2 = NULL;
        while(temp1) {
            temp2 = temp1->next;
            if(!trav || !trav->next || (trav->next->val >= temp1->val))
                trav = prev;
            while(trav->next && (trav->next->val < temp1->val)) {
                trav = trav->next;
            }
            
            temp1->next = trav->next;
            trav->next = temp1;
            temp1 = temp2;
        }
        
        return prev->next;
    }
};

/* Solution 2 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* prev = NULL, *trav, *temp1 = head, *temp2;
        while(temp1) {
            trav = temp1;
            temp2 = temp1->next;
            temp1->next = prev;
            
            int t = temp1->val;
            while(temp1->next && (temp1->next->val < t)) {
                temp1->val = temp1->next->val;
                temp1 = temp1->next;
            }
            
            temp1->val = t;
            prev = trav;
            temp1 = temp2;
        }
        
        return trav;
    }
};

/* Solution 1 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        ListNode* t = head;
        while(t) {
            v.push_back(t->val);
            t = t->next;
        }
        
        //insertion sort
        int j, temp;
        for(int i = 1; i < v.size(); i++) {
            j = i, temp = v[i];
            while(j >= 1 && (v[j] < v[j-1]))
                swap(v[j], v[j-1]), j--;
            
            v[j] = temp;
        }
        
        j = 0, t = head;
        while(t) {
            t->val = v[j++];
            t = t->next;
        }
        
        return head;
    }
};
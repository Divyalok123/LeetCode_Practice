/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3593/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* prev = NULL, *thisnode = head, *anshead = NULL;
        int count = 0;
        while(thisnode) {
            while(thisnode->next && thisnode->next->val == thisnode->val)
            {
                thisnode = thisnode->next;
                count++;
            }
            
            if(count) {
                count = 0;
            } else {
                if(!prev) {
                    prev = thisnode;
                    anshead = prev;
                } else {
                    prev->next = thisnode;
                    prev = prev->next;
                }
            }
            
            if(thisnode) thisnode = thisnode->next;
        }

        if(prev) prev->next = NULL;
        return anshead;
    }
};

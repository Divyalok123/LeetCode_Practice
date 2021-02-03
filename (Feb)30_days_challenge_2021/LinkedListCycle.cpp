/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3627/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return 0;

        ListNode* slow = head, *fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while(fast && fast->next && slow != fast);
        
        return slow == fast;
    }
};
/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/
*/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL, *held = NULL, *curr = fast;
        while (curr != NULL)
        {
            held = curr->next;
            curr->next = prev;
            prev = curr;
            curr = held;
        }
        fast = prev;
        slow = head;
        curr = slow;
        while (slow && fast)
        {
            held = slow->next;
            prev = fast->next;
            slow->next = fast;
            fast->next = held;
            slow = held;
            fast = prev;
        }
        // head = curr;
    }
};
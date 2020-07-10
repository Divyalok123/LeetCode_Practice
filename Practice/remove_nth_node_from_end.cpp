#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head, *curr = NULL;

        while (n--)
            temp = temp->next;
        while (temp != NULL)
        {
            temp = temp->next;
            curr = curr == NULL ? head : curr->next;
        }

        if (curr == NULL)
            return head->next;
        ListNode *t = curr->next;
        curr->next = curr->next->next;
        delete t;
        return head;
    }
};
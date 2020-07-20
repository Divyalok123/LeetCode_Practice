/* Remove all elements from a linked list of integers that have value val. */

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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;

        ListNode *temp = head, *prev = NULL;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                ListNode *del = temp;
                if (prev == NULL)
                {
                    temp = temp->next;
                    head = temp;
                }
                else
                {
                    prev->next = temp->next;
                    temp = temp->next;
                }
                delete del;
            }
            else
            {
                prev = temp;
                if (temp)
                    temp = temp->next;
            }
        }
        return head;
    }
};
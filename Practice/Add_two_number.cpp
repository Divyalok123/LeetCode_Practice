#include <iostream>
#include <algorithm>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *output = new ListNode(0);
        ListNode *ans = output;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            ListNode *newnode = new ListNode(sum % 10);
            output->next = newnode;
            output = output->next;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int sum = l1->val + carry;
            ListNode *newnode = new ListNode(sum % 10);
            output->next = newnode;
            output = output->next;
            carry = sum / 10;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int sum = l2->val + carry;
            ListNode *newnode = new ListNode(sum % 10);
            output->next = newnode;
            output = output->next;
            carry = sum / 10;
            l2 = l2->next;
        }

        if (carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            output->next = newNode;
            output = newNode;
        }
        output->next = NULL;
        return ans->next;
    }
};
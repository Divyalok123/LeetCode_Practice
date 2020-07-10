/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.
*/

#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
            return head;
        if (head->next == NULL && head->child == NULL)
            return head;

        Node *cur = head, *nxt = NULL, *pre = NULL;
        while (cur != NULL)
        {
            pre = cur;
            nxt = cur->next;
            if (cur->child)
            {
                cur = flatten(cur->child);
                pre->next = cur;
                cur->prev = pre;
                while (cur->next != NULL)
                {
                    cur = cur->next;
                }
                cur->next = nxt;
                if (nxt)
                    nxt->prev = cur;
            }
            cur = nxt;
        }

        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->child)
                curr->child = NULL;
            curr = curr->next;
        }

        return head;
    }
};

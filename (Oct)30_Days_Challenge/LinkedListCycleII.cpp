/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3509/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution 2 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (!head || !head->next)
            return NULL;

        ListNode *l1 = head, *l2 = head;

        do
        {
            l1 = l1->next;
            l2 = l2->next->next;
        } while (l2 && l2->next && (l1 != l2));

        if (!l2 || !l2->next)
            return NULL;

        l1 = head;
        while (l1 != l2)
        {
            l1 = l1->next;
            l2 = l2->next;
        }

        return l1;
    }
};

/* Solution 1 */
class Solution
{
public:
    unordered_map<ListNode *, bool> umap;

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *l = head;
        while (l)
        {
            if (umap[l])
                return l;
            umap[l] = true;
            l = l->next;
        }
        return NULL;
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/
*/

#include <iostream>
#include <stack>
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

/* Solution 2 */
class Solution
{
public:
    int size(ListNode *ll)
    {
        int count = 0;
        while (ll)
            ll = ll->next, count++;
        return count;
    }

    ListNode *addfront(ListNode *ll, int v)
    {
        ListNode *node = new ListNode(v);
        node->next = ll;
        return node;
    }

    void print(ListNode *ll)
    {
        ListNode *l = ll;
        cout << "LL: ";
        while (l)
        {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
            return l1 ? l1 : l2;

        ListNode *ans = NULL;
        int sum, size1 = size(l1), size2 = size(l2);
        while (size1 > 0 && size2 > 0)
        {
            sum = 0;
            if (size1 >= size2)
            {
                sum += l1->val;
                l1 = l1->next, size1--;
            }

            if (size2 > size1)
            {
                sum += l2->val;
                l2 = l2->next, size2--;
            }
            ans = addfront(ans, sum);
        }

        ListNode *curr = NULL;
        int carry = 0;
        while (ans)
        {
            ans->val += carry;
            carry = ans->val / 10;
            curr = addfront(curr, ans->val % 10);
            ans = ans->next;
        }

        if (carry)
            curr = addfront(curr, 1);
        return curr;
    }
};

/* SOlution 1 */
class Solution
{
public:
    ListNode *reverse(ListNode *ll)
    {
        ListNode *prev = NULL, *curr = ll, *next = ll;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
            return l1 ? l1 : l2;

        ListNode *ans = l1, *temp;
        l1 = reverse(l1), l2 = reverse(l2);
        temp = l1;
        int sum, carry = 0;
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ans = l1;
            l1->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            ans = l1;
            l1 = l1->next;
        }

        while (l2)
        {
            sum = l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;
            if (!ans->next)
            {
                ans->next = l2;
            }
            ans = l2;
            l2 = l2->next;
        }

        if (carry)
            ans->next = new ListNode(1);

        temp = reverse(temp);
        return temp;
    }
};
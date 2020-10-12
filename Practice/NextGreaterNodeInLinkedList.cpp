/*
https://leetcode.com/problems/next-greater-node-in-linked-list/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        if (!head)
            return {};

        stack<int> s;
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size(), temp;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && (s.top() <= v[i]))
                s.pop();
            temp = v[i];
            v[i] = s.empty() ? 0 : s.top();
            s.push(temp);
        }
        return v;
    }
};
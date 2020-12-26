/*
https://leetcode.com/problems/swap-nodes-in-pairs/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define node ListNode
class Solution {
public:
    ListNode* swapPairs(ListNode* ll) {
        if(!ll || !ll->next) return ll;
        node* temp = ll, *t, *tt;
        node* ans = new node(0);
        node* tans = ans;
        tans->next = temp;
        int l = 0;
        while(temp) {
            t = temp;
            tt = temp->next;
            if(!tt) break;
            temp = temp->next->next;
            t->next = temp;
            tt->next = t;
            tans->next = tt;
            tans = t;
        }

        return ans->next;
    }
};
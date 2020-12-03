/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3552/
*/

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution 2 */
//considering a stream


/* Solution 1 */
//not considering a stream

class Solution {
    ListNode* root;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): root(head) {srand(0);}
    
    /** Returns a random node's value. */
    int getRandom() {
        int len = 0;
        ListNode* temp = root;
        while(temp)
            temp = temp->next, len++;
        
        len = rand()%len;
        
        temp = root;
        while(len && temp) {
            temp = temp->next;
            len--;
        }
        
        return temp->val;
    }
};
/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* ans = head, *temp = head, *prev = NULL;
        unordered_map<int, ListNode*> um;
        
        int till = 0;
        while(temp) {
            till += temp->val;
            
            if(till == 0) {
                ListNode* temp2 = temp->next;
                
                int sum = 0;
                while(ans != temp2) {
                    sum += ans->val;
                    um.erase(sum);
                    ans = ans->next;
                }
                
                ans = temp2;
                
            } else {
                if(um.count(till)) {
                    ListNode* t = um[till];
                    prev = t->next;
                    
                    int val = till + prev->val;
                    while(val != till) {
                        um.erase(val);
                        prev = prev->next;
                        val += prev->val;
                    }
                    
                    t->next = temp->next;
                } else {
                    um[till] = temp;
                }
            }
            
            temp = temp->next;
        }
        
        return ans;
    }
};

// O(n^2)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head, *prev = NULL;
        while(temp) {
            if(prev)
                temp->val += prev->val;

            ListNode* newtemp = prev;

            if(temp->val == 0) {
                prev = NULL;
                temp = temp->next;
                continue;
            } else { 
                while(newtemp != NULL) {
                    if(newtemp->val == temp->val)
                    {
                        prev = newtemp;
                        temp = temp->next;
                        break;
                    }
                    
                    newtemp = newtemp->next;
                }
                
                if(newtemp)
                    continue;
            }
            
            newtemp = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newtemp;
        }
          
        temp = prev;
        prev = NULL;
        
        while(temp) {
            ListNode* n = temp->next;
            if(n) temp->val -= n->val;

            temp->next = prev;
            prev = temp;
            temp = n;
        }
        cout << endl;
        
        return prev;
    }
};
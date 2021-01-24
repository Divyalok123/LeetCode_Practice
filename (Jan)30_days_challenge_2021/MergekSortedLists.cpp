/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3615/
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution 3 */
class Solution {
public:
    ListNode* merge(ListNode* one, ListNode* two) {
        if(!one || !two)
            return one ? one : two;
        
        if(one->val < two->val) {
            one->next = merge(one->next, two);
            return one;
        } 

        two->next = merge(one, two->next);
        return two;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j) {
        if(i > j) return NULL;
        if(i == j) return lists[i];
        if(i == j-1) return merge(lists[i], lists[j]);
        int m = i + (j-i)/2;
        ListNode* l = mergeKLists(lists, i, m);
        ListNode* r = mergeKLists(lists, m+1, j);
        return merge(l, r);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size()-1);
    }
};

/* Solution 2 */
class Solution {
public:
    ListNode* merge(ListNode* one, ListNode* two) {
        if(!one || !two)
            return one ? one : two;
        
        ListNode* ans = new ListNode(0), *temp;
        temp = ans;
        while(one && two) {
            if(one->val < two->val) {
                temp->next = one;
                one = one->next;
            } else {
                temp->next = two;
                two = two->next;
            }
            temp = temp->next;
        }
        temp->next = one ? one : two;       
        return ans->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
            
        int n = lists.size();
        int i, j;
        while(n > 1) { 
            i = 0, j = n-1;
            while(i < j) {
                lists[i] = merge(lists[i], lists[j]);
                i++, j--;
            }
            n = (n+1)/2;
        }
        
        return lists[0];
    }
};

/* Solution 1 */
class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto i: lists)
            if(i)
                pq.push(i);
        
        ListNode* ans = NULL, *temp = NULL;
        while(pq.size()) {
            auto f = pq.top();
            pq.pop();
            
            if(ans == NULL) {
                ans = f;
                temp = ans;
            } else {
                temp->next = f;
                temp = temp->next;
            }
            
            if(f->next)
                pq.push(f->next);
        }
        
        return ans;
    }
};
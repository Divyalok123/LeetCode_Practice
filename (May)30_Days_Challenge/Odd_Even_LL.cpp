// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Final Solution (More Elegant)
//Method: Breaking into odd and even and joining
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        
        ListNode* evenPtr = head->next;
        ListNode* oddPtr = head;
        ListNode* evenHead = head->next;
        
        while(evenPtr != NULL && evenPtr->next != NULL)
        {
            oddPtr->next = oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        
        oddPtr->next = evenHead;
        
        return head;
        
    }
};

//Initial Solution (Without much optimisation either)
//Method: swapping 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        ListNode* lastNode = head; //reaching last node
        if(len%2 != 0)
        {
            while(lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            
            ListNode* tailPtr = lastNode;
            ListNode* headPtr = head;

            while(headPtr != lastNode)
            {
                ListNode* nextPtr = headPtr->next;
                headPtr->next = headPtr->next->next;
                tailPtr->next = nextPtr;
                nextPtr->next = NULL;
                tailPtr = nextPtr;
                headPtr = headPtr->next;
            }
        }
        else
        {
            while(lastNode->next->next != NULL)
            {
                lastNode = lastNode->next;
            }
                    
            ListNode* tailPtr = lastNode->next;
            ListNode* preLast = lastNode;
            ListNode* headPtr = head;

            while(headPtr != lastNode)
            {
                ListNode* nextPtr = headPtr->next;
                headPtr->next = headPtr->next->next;
                preLast->next = nextPtr;
                nextPtr->next = tailPtr;
                preLast = nextPtr;
                headPtr = headPtr->next;
            }
        }        
        
        return head;
    }
};
// https://leetcode.com/problems/design-linked-list/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1
class node {
public:
    int val;
    node* next;
    
    node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    node* ll;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        ll = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(!ll) return -1;
        
        if(!index) return ll->val;
        
        node* temp = ll;
        while(temp && index--) 
            temp = temp->next;
        return temp ? temp->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* n = new node(val);
        
        if(ll) 
            n->next = ll;
        
        ll = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* n = new node(val);
        
        if(ll) {
            node* nn = ll;
            while(nn->next)
                nn = nn->next;
            nn->next = n;
        } else
            ll = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node* prev = NULL, *temp = ll;
        
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        while(index && temp) {
            prev = temp;
            temp = temp->next;
            index--;
        }
        
        if(index) return;
        
        if(!index && !temp) {
            prev->next = new node(val);
            return;
        }
        
        node* n = temp;
        prev->next = new node(val);
        prev->next->next = n;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(ll) {
            if(!index)
                ll = ll->next;
            else {
                node* prev = NULL, *temp = ll;
                while(temp && index) {
                    prev = temp;
                    temp = temp->next;
                    index--;
                }
                
                if(!temp) return;
                
                prev->next = temp->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
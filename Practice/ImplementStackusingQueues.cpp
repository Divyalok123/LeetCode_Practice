/*
https://leetcode.com/problems/implement-stack-using-queues/
*/

#include <iostream>
#include <queue>
using namespace std;

/* Solution 3 */


/* Solution 2 (Only push is O(N)) */
class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int n, size = q.size();
        for(int i = 0; i < size-1; i++) {
            n = q.front();
            q.pop();
            q.push(n);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};


/* Solution 1 (top or pop are O(N))*/
class MyStack {
    queue<int> q;
    queue<int> tq;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans;
        while(q.size() != 1) {
            tq.push(q.front());
            q.pop();
        }
        
        ans = q.front();
        q.pop();
        
        while(tq.size() != 0)
        {
            q.push(tq.front());
            tq.pop();
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int ans;
        while(q.size() != 1) {
            tq.push(q.front());
            q.pop();
        }
        
        ans = q.front();
        q.pop();
        tq.push(ans);
        
        while(tq.size() != 0)
        {
            q.push(tq.front());
            tq.pop();
        }
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
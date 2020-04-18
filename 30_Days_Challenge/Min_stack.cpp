// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

// Example:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    vector<int> *v;
    vector<int> min;

public:
    /* initialize your data structure here. */
    MinStack()
    {
        v = new vector<int>();
    }

    void push(int x)
    {
        v->push_back(x);
        if (min.empty() || min.back() >= x)
            min.push_back(x);
    }

    void pop()
    {
        if (v->size() == 0)
            return;
        if (v->back() == min.back())
            min.pop_back();
        v->pop_back();
    }

    int top()
    {
        if (v->size() == 0)
            return -1;
        return v->back();
    }

    int getMin()
    {
        if (min.empty())
            return -1;
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
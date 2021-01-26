/*
https://leetcode.com/problems/peeking-iterator/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Iterator {
public:
	struct Data;
    Data* data;
	Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
    bool check;
    int checked;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        check = 0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!check) checked = Iterator::next();
        check = 1;
        return checked;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(!check) checked = Iterator::next();
        check = 0;
        return checked;
	}
	
	bool hasNext() const {
        return check || Iterator::hasNext();
	}
};
/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3633/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
    Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);

        // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// Solution 2
class PeekingIterator : public Iterator {
    bool hasnext;
    int nextval;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasnext = Iterator::hasNext();
        if(hasnext)
            nextval = Iterator::next();
	}
	
	int peek() {
        return nextval;
    }
    
	int next() {
        int ans = nextval;
        hasnext = Iterator::hasNext();
        if(hasnext)
            nextval = Iterator::next();
        return ans;
	}
	
	bool hasNext() const {
        return hasnext;
	}
};

// Solution 1
class PeekingIterator : public Iterator {
    int ind;
    vector<int> vec;
    bool checked;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        vec = nums;
        ind = 0;
        checked = 1;
	}
	
	int peek() {
        if(checked) return vec[ind];
        if(!hasNext()) return -1;
        checked = 1;
        ind++;
        return vec[ind];
	}
	
	int next() {
        if(checked) {
            int ans = vec[ind];
            checked = 0;
            return ans;
        }
        
        if(ind == vec.size()-1) 
            return -1;
        
        checked = 0;
        ind++;
        return vec[ind];
	}
	
	bool hasNext() const {
        return checked || (ind < vec.size()-1);
	}
};
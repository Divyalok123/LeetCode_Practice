/*
https://leetcode.com/problems/rle-iterator/
*/

#include <iostream>
#include <vector>
using namespace std;

class RLEIterator {
    vector<int> v;
    int sz;
    int i;
public:
    RLEIterator(vector<int>& A): v(A), i(0), sz(A.size()) {}
    
    int next(int n) {
        if(i == sz) return -1;
        
        while(i < sz && v[i] < n)
            n -= v[i], i+=2;
        
        if(i == sz) return -1;
        
        v[i] -= n;
        return v[i+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
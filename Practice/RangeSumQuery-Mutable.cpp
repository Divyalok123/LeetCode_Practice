/*
https://leetcode.com/problems/range-sum-query-mutable/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class NumArray {
    vector<int> v;
    vector<int> bitree;
    int maxval;
public:
    
    void bitupdate(int i, int val) {
        while(i < maxval) {
            bitree[i] += val;
            i += (i & -i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while(i) {
            sum += bitree[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    NumArray(vector<int>& nums) {
        v = nums;
        maxval = nums.size()+1;
        bitree.resize(maxval);
        
        for(int i = 0; i < maxval-1; i++) 
            bitupdate(i+1, nums[i]);
    }
    
    void update(int i, int val) {
        bitupdate(i+1, val-v[i]);
        v[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(j+1)-query(i);
    }
};
/*
https://leetcode.com/problems/gray-code/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

// Solution 3
class Solution {
public:
    int k;
    void backtrack(vector<int>& ans, int n, bitset<32>& b) {
        if(n == 0) {
            ans[k++] = b.to_ulong();
            return;
        }
        
        backtrack(ans, n-1, b);
        b.flip(n-1);
        backtrack(ans, n-1, b);
    }
    
    vector<int> grayCode(int n) {
        if(n == 1) return {0, 1};
        k = 0;
        int lim = 1 << n;
        vector<int> ans(lim);
        bitset<32> b;
        backtrack(ans, n, b);
        return ans;
    }
};

// Solution 2 
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return {0, 1};
        
        int lim = 1 << n;
        vector<int> ans(lim);
        ans[0] = 0;
        ans[1] = 1;
        
        int sz = 2, k = 2, val = 1;
        for(int i = 1; i < n; i++) {
            val <<= 1;
            for(int j = sz-1; j >= 0; j--) 
                ans[k++] = (ans[j] | val);
            sz *= 2;
        }
        
        return ans;
    }
};

// Solution 1 (src: cp-algo)
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return {0, 1};
        
        int lim = 1 << n;
        vector<int> ans(lim);
                
        for(int i = 0; i < lim; i++) 
            ans[i] = i ^ (i >> 1);

        return ans;
    }
};
/*
https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//using observation (and leetcode discuss)
class Solution {
public:
    int reinitializePermutation(int n) {
        if(n == 2) return 1;
        int ans = 0, ind = 1, two = 1;
        while(1) {
            ind = (ind+two)%(n-1);
            ans++;

            if(ind == 1)
                break;
            two = (two*2ll)%(n-1);
        }
        
        return ans;
    }
};

// simple brute force
class Solution {
public:
    void change(vector<int>& v) {
        int n = v.size();
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = (i&1) ? v[n/2 + i/2] : v[i/2];
        v = arr;
    }
    
    int reinitializePermutation(int n) {
        vector<int> v(n);

        iota(v.begin(), v.end(), 0);
        int ans = 0;
        
        vector<int> arr = v;
        while(1) {
            change(arr);
            ans++;
            
            if(v == arr)
                break;
        }
        
        return ans;
    }
};
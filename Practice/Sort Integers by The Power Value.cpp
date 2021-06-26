/*
https://leetcode.com/problems/sort-integers-by-the-power-value/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//faster
class Solution {
public:
    static int powerv(int j, unordered_map<int, int>& store) {
        if(j == 1) return 0;
        if(store[j]) return store[j];
        
        if(j&1)
            return store[j] = 1 + powerv(j*3 + 1, store);
        return store[j] = 1 + powerv(j/2, store);
    }
    
    static vector<int> func() {
        unordered_map<int, int> store;
        vector<int> vec(1000);
        vec[0] = 1;
        for(int i = 1; i < 1000; i++)
            vec[i] = powerv(i+1, store);
        return vec;
    }
    
    
    
    int getKth(int lo, int hi, int k) {
        static auto vec = func();
        int n = hi-lo+1;
        vector<int> newv(n);
        iota(newv.begin(), newv.end(), lo);
        nth_element(newv.begin(), newv.begin() + k - 1, newv.end(), [](int a, int b){
            return vec[a-1] < vec[b-1] || (vec[a-1] == vec[b-1] && a < b);
        });
        
        return newv[k-1];
    }
};

// storing and nth_element
class Solution {
public:
    
    int powerv(int j) {
        int count = 0;
        while(j > 1) {
            if(j&1)
                j = j*3 + 1;
            else
                j/=2;
            count++;
        }
        
        return count;
    }
    
    int getKth(int lo, int hi, int k) {
        int n = hi-lo+1;
        vector<array<int, 2>> vec(n);
        
        for(int i = 0, j = lo; i < n; i++, j++)
            vec[i] = {powerv(j), j};

        nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        
        return vec[k-1][1];
    }
};
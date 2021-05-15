/*
https://leetcode.com/problems/bitwise-ors-of-subarrays/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_set>
using namespace std;

// Improved
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<int> store;
        store.reserve(50000);
        store.push_back(arr[0]);
        
        int l = 0;
        for(int i = 1; i < n; i++) {
            int r = store.size()-1;
            store.push_back(arr[i]);
            for(int j = l; j <= r; j++) {
                int val = (arr[i] | store[j]);
                if(store.back() != val)
                    store.push_back(val);
            }
            l = r+1;
        }
        
        return unordered_set<int>(store.begin(), store.end()).size();
    }
};

// Brute force
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<unordered_set<int>> store(n);
        unordered_set<int> ans;
        
        store[0].insert(arr[0]);
        ans.insert(arr[0]);
        
        for(int i = 1; i < n; i++) {
            store[i].insert(arr[i]);
            ans.insert(arr[i]);
            
            for(int j: store[i-1]) {
                int val = j | arr[i];
                store[i].insert(val);
                ans.insert(val);
            }
        }
        
        return ans.size();
    }
};
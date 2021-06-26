/*
https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<long long> store(n); 
        
        for(int i = 0; i < n; i++) {
            long long val = 0;
            for(auto& j: words[i])
                val |= (1 << (j-'a'));
            store[i] = val;
        }
        
        size_t ans = 0;
        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                 if((store[i]&store[j]) == 0)
                     ans = max(ans, words[i].size() * words[j].size());
        
        return ans;
    }
};
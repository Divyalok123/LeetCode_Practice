/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3618/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Storing the values
vector<int> store(100001, -1);
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, p = 0, MOD = 1e9+7;
        if(store[n] != -1) return store[n];
        for(int i = 1; i <= n; i++) {
            if((i&(i-1)) == 0) 
                p++;

            ans = (ans << p)%MOD;
            ans = (ans + i)%MOD;
            store[i] = ans;
        }
        
        return ans;
    }
};

// Solution 1
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, p = 0, MOD = 1e9+7;
        for(int i = 1; i <= n; i++) {
            // cout << "i: "  << i << endl;
            if((i&(i-1)) == 0) 
                p++;

            ans = (ans << p)%MOD;
            ans = (ans + i)%MOD;
            
        }
        
        return ans;
    }
};
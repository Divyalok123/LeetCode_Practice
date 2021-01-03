/*
https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3591/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 3 (memoizing solution 1) (4ms) */
class Solution {
public:
    vector<int> v;
    int helper(int mask, int n, int ind) {
        if(ind == n+1) return 1;
        
        int ans = 0;
        if(v[mask] != -1) return v[mask];
        
        for(int i = 1; i <= n; i++) {
            if(!(mask & (1 << i-1)) && (i%ind == 0 || ind%i == 0)) {
                mask ^= (1 << (i-1));
                ans += helper(mask, n, ind+1);
                mask ^= (1 << (i-1));
            }
        }
        
        return v[mask] = ans;
    }
    
    
    int countArrangement(int n) {
        int mask = 0;
        v.resize(33000, -1);
        return helper(mask, n, 1);
    }
};

/* Solution 2 (factorial) (12ms) */
class Solution {
public:
    int helper(vector<int>& v, int n) {
        if(n == 0) return 1;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(v[i]%(n)==0 || (n)%v[i]==0) {
                swap(v[i], v[n-1]);
                ans += helper(v, n-1); //n is decreasing 
                swap(v[i], v[n-1]);
            }
        }
        
        return ans;
    }
    
    
    int countArrangement(int n) {
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = i+1;
        }
        return helper(v, n);
    }
};

/* Solution 1 (Exponential with base n) (240ms) */
class Solution {
public:
    vector<bool> v;
    int countArrangement(int n, int i = 1) {
        if(i == n+1) return 1;
        
        if(v.size() == 0) 
            v.assign(n, 0);
        
        int ans = 0;
        for(int j = 1; j <= n; j++) {
            if((j%i == 0 || i%j == 0) && v[j-1] == 0) {
                v[j-1] = 1;
                ans += countArrangement(n, i+1);
                v[j-1] = 0;
            }
        }
        
        return ans;
    }
};
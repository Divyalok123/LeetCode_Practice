/*
https://leetcode.com/problems/integer-replacement/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// iterative
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n == INT_MAX) return 32;
        
        int ans = 0;
        while(n > 1) {
            if(n&1) {
                if(n == 3 || ((n >> 1) & 1) == 0)
                    n--;
                else
                    n++;
            } else 
                n/=2;
            
            ans++;
        }
        
        return ans;
    }
};

// simple dfs
class Solution {
public:
    int integerReplacement(long long n) {
        if(n == 1) return 0;
        
        if(n&1) 
            return 2 + min(integerReplacement((n-1)/2), integerReplacement((n+1)/2));
        
        return 1 + integerReplacement(n/2);
    }
};
/*
https://leetcode.com/problems/clumsy-factorial/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// smarter O(1) solution
class Solution {
public:
    int clumsy(int n) {
        if(n <= 2) return n;
        if(n <= 4) return n + 3;
        
        if(n%4 == 0)
            return n + 1;
        else if(n%4 <= 2)
            return n + 2;
        return n - 1;
    }
};

// recursive
class Solution {
public:
    
    int helper(int n) {
        if(n <= 2) return -n;
        if(n == 3) return -6;
        return -(n*(n-1)/(n-2)) + (n-3) + helper(n-4);
    }
    
    int clumsy(int n) {
        if(n <= 2) return n;
        if(n == 3) return 6;
        return n * (n-1) / (n-2) + (n-3) + helper(n-4);
    }
};

// simple iterative
class Solution {
public:
    int clumsy(long long n) {
        if(n <= 2) return n;
        
        long long ans = 0;
        bool check = 0;
        while(n) {
            if(n >= 4) {
                int val = (n * (n-1) / (n-2));
                n-= 3;
                if(!check) {
                    ans += val;
                    ans += n--;
                } else {
                    ans -= val;
                    ans += n--;
                }
            } else {
                int val = n--;
                if(n) val *= n--;
                if(n) val /= n--;
                
                if(!check)
                    ans += val;
                else
                    ans -= val;
                
                if(n) ans += n--;
                if(n) ans -= n--;
            } 
            
            check = 1;
        }
        
        return ans;
    }
};
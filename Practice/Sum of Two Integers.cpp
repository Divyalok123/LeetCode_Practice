/*
https://leetcode.com/problems/sum-of-two-integers/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// better
class Solution {
public:
    int getSum(int a, int b) {
      unsigned int c; 
      while(b !=0 ) {
        c = (a&b);   
        a = a ^ b;
        b = (c)<<1;
      }
        
      return a;
    }
};

// not totally correct.. won't work if answer is negative
class Solution {
public:
    int getSum(int a, int b) {
        bool check = 0;
        if(a < 0 && b < 0) {
            check = 1;
            a *= -1;
            b *= -1;
        }
        
        int ans = 0, carry = 0;
        for(int i = 0; i <= 10; i++) {
            int mask = (1 << i);
            int x = a&mask, y = b&mask;
            
            if(x && y && carry) {
                carry = 1;
                ans |= mask;
            } else if(((x || y) && carry) || (x && y)) {
                carry = 1;
            } else if(x || y || carry) {
                ans |= mask;
                carry = 0;
            }
        }
        
        return check ? -1*ans : ans;
    }
};
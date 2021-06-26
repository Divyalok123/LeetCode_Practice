/*
https://leetcode.com/problems/nth-digit/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int base = 9, digit = 1;
        while(n - base * 1ll * digit > 0) {
            n -= base*digit;
            base *= 10;
            digit++;
        }
        
        int rem = (n-1)/digit;
        int md = n%digit - 1;
        if(md < 0) md += digit;
        
        int num = 1;
        while(--digit) 
            num *= 10;
        
        num += rem;
        string s = to_string(num);
        return s[md] - '0';
    }
};
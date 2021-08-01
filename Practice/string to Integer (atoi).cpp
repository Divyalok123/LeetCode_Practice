/*
https://leetcode.com/problems/string-to-integer-atoi/
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        int check = 1;
        if(s[i] == '-') check = -1, i++;
        else if (s[i] == '+') i++;
        
        if(i == n || !(s[i] >= '0' && s[i] <= '9')) return 0;
        
        long long ans = 0;
        while(i < n && (s[i] >= '0' && s[i] <= '9')) {
            ans = (ans * 10 + (s[i]-'0')), i++;
            if(check * ans < INT_MIN)
                return INT_MIN;
            if(check * ans > INT_MAX)
                return INT_MAX;
        }
        
        return check * ans;
    }
};
/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3646/
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 2
class Solution {
public:
    int refval(char& s) {
        if(s == 'I') return 1;
        else if(s == 'V') return 5;
        else if(s == 'X') return 10;
        else if(s == 'L') return 50;
        else if(s == 'C') return 100;
        else if(s == 'D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
        int i = 0, n = s.size(), ans = 0;
        while(i < n-1) {
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) 
                ans += refval(s[i++ +1])-1;
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) 
                ans += refval(s[i++ +1])-10;
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) 
                ans += refval(s[i++ +1])-100;
            else 
                ans += refval(s[i]);
            i++;
        }
        
        if(i < n)
            ans += refval(s[i]);
        
        return ans;
    }
};

// Solution 1
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> um;
        um["I"] = 1;
        um["V"] = 5;
        um["X"] = 10;
        um["L"] = 50;
        um["C"] = 100;
        um["D"] = 500;
        um["M"] = 1000;
        um["IV"] = 4;
        um["IX"] = 9;
        um["XC"] = 90;
        um["XL"] = 40;
        um["CD"] = 400;
        um["CM"] = 900;
        
        int i = 0, n = s.size(), ans = 0;
        while(i < n-1) {
            string st = s.substr(i, 2);
            string ss = s.substr(i, 1);
            int val = um[st];
            if(val) {
                ans += val;
                i+=2;
            } else {
                ans += um[ss];
                i++;
            }
        }
        
        if(i < n)
            ans += um[s.substr(i, 1)];
        
        return ans;
    }
};
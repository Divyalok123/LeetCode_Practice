/*
https://leetcode.com/contest/biweekly-contest-48/problems/second-largest-digit-in-a-string/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int ans = -1, largest = -1;
        for(char& c: s) {
            if(isdigit(c))
            {
                if(largest < c-'0')
                {
                    ans = largest;
                    largest = c-'0';
                } else if(largest > c-'0' && ans < c-'0') {
                    ans = c-'0';
                }
            }
        }
        
        return ans;
    }
};
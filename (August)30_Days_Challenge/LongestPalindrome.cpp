/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3423/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(256, 0);
        for(char &c: s)
            v[c-'A']++;
        
        int twocounts = 0;
        bool onep = false;
        for(int &a: v) 
        {
            if(a%2 == 0) twocounts += a;
            if(a%2) {
                onep = true;
                twocounts += (a-1);
            }
        }
        
        return twocounts+onep;
    }
};
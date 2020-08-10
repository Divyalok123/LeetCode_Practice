/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3419/
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int a = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            a += (s[i]-'A'+1)*pow(26, n-i-1);
        }
        return a;
    }
};
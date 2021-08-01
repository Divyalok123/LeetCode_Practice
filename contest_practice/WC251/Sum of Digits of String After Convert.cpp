/*
https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c: s) {
            int v = c-'a'+1;
            while(v)
            {
                sum += v % 10;
                v/=10;
            }
        }
        
        while(--k) {
            int newsum = sum;
            sum = 0;
            while(newsum) {
                sum += newsum % 10;
                newsum/=10;
            }
        }
        
        return sum;
    }
};
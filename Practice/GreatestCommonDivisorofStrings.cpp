/*
https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

/* Solution 2 */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1)
            return str1.substr(0, __gcd(str1.size(), str2.size()));
        return "";
    }
};

/* Solution 1 */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() == 0 || str2.size() == 0)
            return "";
        else if(str1 == str2)
            return str1;
        else 
        {
            if(str1.size() > str2.size()) {
                if(strncmp(str1.c_str(), str2.c_str(), str2.size()) == 0)
                    return gcdOfStrings(str2, str1.substr(str2.size()));
                else
                    return "";
            } else {
                if(strncmp(str2.c_str(), str1.c_str(), str1.size()) == 0)
                    return gcdOfStrings(str1, str2.substr(str1.size()));
                else
                    return "";
            }
        }
    }
};
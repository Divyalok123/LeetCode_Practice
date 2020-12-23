/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3578/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n/10 == 0) return -1;
        string s = to_string(n);
        int sz = s.size();
        int i = sz-1;
        while(i > 0 && s[i] <= s[i-1]) i--;
        if(i == 0) return -1;
        i--;
        int j = sz-1;
        while(j > i && s[j] <= s[i]) j--;
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        long long val = stoll(s);
        return val > INT_MAX ? -1 : val;
    }
};

/* Solution 1 (STL) */
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(next_permutation(s.begin(), s.end())) {
            long long ans = stoll(s);
            return ans > INT_MAX ? -1 : (int)ans;
        }
        return -1;
    }
};
/*
https://leetcode.com/contest/weekly-contest-238/problems/sum-of-digits-in-base-k/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while(n) {
            ans += n%k;
            n/=k;
        }
        
        return ans;
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3543/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k&1) {
            if(k%10 == 5) return -1;
            int val = 0;
            for(int i = 1; i <= k; i++)
                if(val = (val*10 + 1)%k == 0)
                    return i;
        }   
        return -1;
    }
};
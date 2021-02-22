/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3647/
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Solution 2
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X > Y) return X-Y;
        if(X == Y) return 0;
        
        int count1 = 0, mul = 1;
        while(X*mul < Y)
            mul <<= 1, count1++;
        
        int rem = X*mul - Y, count2 = 0;
        int i = count1;
        while(rem) {
            int power = (1 << i--);
            int coeff = rem/power;
            rem %= power;
            count2 += coeff;
        }
        
        return count1 + count2;
    }
};

// Solution 1
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X > Y) return X-Y;
        if(X == Y) return 0;
        return 1 + (Y&1 ? brokenCalc(X, Y+1) : brokenCalc(X, Y/2)); 
    }
};
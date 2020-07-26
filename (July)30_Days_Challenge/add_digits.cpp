/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
*/

#include <iostream>
using namespace std;

static int x = [](){ios_base::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        if(num%9 == 0)
            return 9;
        else return num%9;
    }
};
/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    double angleClock(int h, int m)
    {
        double rem = ((double)m / 60) * 5;
        double add = abs(rem + 5 * (double)h - (double)m);
        if (add > 30)
            add = 60 - add;
        double ans = add * 6;
        ans *= 100000;
        int new_ans = (int)ans;
        ans = (double)new_ans / 100000;
        return ans;
    }
};
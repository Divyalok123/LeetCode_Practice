/* https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3412/ */

#include <iostream>
#include <cmath>
using namespace std;

/* one liner */
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && ((n & (n - 1)) == 0) && ((int)log2(n) % 2 == 0);
    }
};

/* way1 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num && floor(log2(num)) == log2(num))
        {
            if((int)(log2(num))%2 == 0)
                return true;
        }
        return false;
    }
};
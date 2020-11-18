/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3534/
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/* Solution 1 */
class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p==q) return 1;
        int sum = 0, lr = 1, ud = 1;
        while(true) {
            if(sum == p)
                break;

            sum += q;
            lr ^= 1;
            if(sum > p) 
                sum -= p, ud ^= 1;
        }
        return ud ? lr+1 : 0;
    }
};
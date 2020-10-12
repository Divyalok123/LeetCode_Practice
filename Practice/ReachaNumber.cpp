/*
https://leetcode.com/problems/reach-a-number/
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int reachNumber(int target)
    {
        if (target == 0)
            return 0;
        target = abs(target);
        int steps = 1;
        int sum = 0;
        while (1)
        {
            sum += steps;
            if (sum > target && ((sum - target) % 2 == 0))
                return steps;
            if (sum == target)
                return steps;
            steps++;
        }
    }
};
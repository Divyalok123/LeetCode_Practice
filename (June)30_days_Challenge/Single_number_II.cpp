// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*---------------------*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

/*---------------------*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;
        int threes = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            twos |= (ones & nums[i]);
            ones ^= nums[i];
            threes = ~(twos & ones);
            ones &= threes;
            twos &= threes;
        }
        return ones;
    }
};
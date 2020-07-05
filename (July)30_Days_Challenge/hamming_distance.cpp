// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.

#include <iostream>
using namespace std;

class Solution
{
public:
    int count_set_bits(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    int hammingDistance(int x, int y)
    {
        int xor_val = x ^ y;
        return count_set_bits(xor_val);
    }
};
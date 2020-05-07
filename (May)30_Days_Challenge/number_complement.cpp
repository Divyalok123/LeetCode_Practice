// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

#include <iostream>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int bits = log2(num) + 1;
        
        for (int i = 0; i < bits; i++)
        {
            num = num ^ (1 << i);
        }

        return num;
    }
};
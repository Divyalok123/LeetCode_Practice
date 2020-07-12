/*
Reverse bits of a given 32 bits unsigned integer.
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <bitset>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> bt(n);
        int i = 0, j = 31;
        while (i < j)
        {
            int temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            i++;
            j--;
        }

        return bt.to_ulong();
    }
};
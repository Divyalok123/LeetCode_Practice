/*
Reverse bits of a given 32 bits unsigned integer.
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <bitset>
using namespace std;

//solution 2
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++)
        {
            ans = (ans << 1) + (n >> i & 1);
        }
        return ans;
    }
};

//solution 1 (better)
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
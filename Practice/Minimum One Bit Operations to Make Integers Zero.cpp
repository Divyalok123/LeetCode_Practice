/*
https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        if(n == 2) return 3;
        if(n == 3) return 2;
        
        int bit = -1;
        for(bit = 1 << 30; bit; bit >>= 1)
            if(n & bit)
                break;

        if(bit == n) 
            return 2*n - 1;
        
        int value = n & (bit - 1);
        int ans = minimumOneBitOperations(value);
        return (bit << 1) - 1 - ans;
    }
};
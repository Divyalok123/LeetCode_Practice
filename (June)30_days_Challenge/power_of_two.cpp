// Given an integer, write a function to determine if it is a power of two.

#include <iostream>
#include <algorithm>
using namespace std;

//solution 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};

//solution 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcount(n) == 1 && n > 0;
    }
};
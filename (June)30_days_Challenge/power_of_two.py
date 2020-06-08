# Given an integer, write a function to determine if it is a power of two.

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return (n&(n-1)) == 0 and n > 0
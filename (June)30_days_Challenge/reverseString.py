# Write a function that reverses a string. The input string is given as an array of characters char[].
# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
# You may assume all the characters consist of printable ascii characters.

from typing import List
class Solution:
    def reverseString(self, s: List[str]) -> None:
        size = len(s)
        if size == 0 or size == 1: return
        i = 0
        j = size-1
        while(i < j):
            s[i], s[j] = s[j], s[i]
            i+=1
            j-=1
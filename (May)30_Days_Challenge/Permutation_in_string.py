# Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

import functools


class Solution:
    def checkInclusion(self, p: str, s: str) -> bool:
        slength = len(s)
        plength = len(p)

        if(plength > slength):
            return False

        sarr = [0]*26
        parr = [0]*26

        for i in range(plength):
            sarr[ord(s[i])-97] += 1
            parr[ord(p[i])-97] += 1

        if functools.reduce(lambda x, y: x and y, map(lambda p, q: p == q, sarr, parr), True):
            return True

        for i in range(plength, slength):
            sarr[ord(s[i])-97] += 1
            sarr[ord(s[i-plength])-97] -= 1
            if functools.reduce(lambda x, y: x and y, map(lambda p, q: p == q, sarr, parr), True):
                return True
        return False

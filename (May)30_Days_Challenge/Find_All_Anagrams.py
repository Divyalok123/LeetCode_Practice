# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

# The order of output does not matter.


import functools
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        slength = len(s)
        plength = len(p)
        
        output = []
        if(plength > slength):
            return output
        
        sarr = [0]*26
        parr = [0]*26
        
        for i in range(plength):
            sarr[ord(s[i])-97]+= 1 
            parr[ord(p[i])-97]+= 1

        if functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q,sarr,parr), True):
            output.append(0)
            
        for i in range(plength, slength):
            sarr[ord(s[i])-97]+= 1
            sarr[ord(s[i-plength])-97]-= 1
            if functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q,sarr,parr), True):
                output.append(i-plength+1)
        return output
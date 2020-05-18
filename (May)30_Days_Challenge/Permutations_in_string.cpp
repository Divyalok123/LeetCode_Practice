// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1vec(26);
        vector<int> s2vec(26);
        
        int s1length = s1.length();
        int s2length = s2.length();
        
        if(s1length > s2length) return false;
        
        for(int i = 0; i < s1length; i++)
        {
            s1vec[s1[i]-'a']++;
            s2vec[s2[i]-'a']++;
        }
        
        if(s1vec == s2vec) return true;
        for(int i = s1length; i < s2length; i++)
        {
            s2vec[s2[i]-'a']++;
            s2vec[s2[i-s1length]-'a']--;
            
            if(s2vec == s1vec)
            {
                return true;
            }
        }
        
        return false;        
    }
};
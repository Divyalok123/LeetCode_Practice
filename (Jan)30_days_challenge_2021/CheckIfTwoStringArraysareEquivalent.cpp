/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3597/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void join(vector<string>& v, string& s) {
        for(auto& i: v)
            s += i;
    }
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        join(word1, s1);
        join(word2, s2);
        return s1 == s2;
    }
};
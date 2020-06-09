// Given a string s and a string t, check if s is subsequence of t.
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

#include <iostream>
#include <vector>
#include <algorithm> //upper_bound
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slength = s.length();
        int tlength = t.length();
        int j = 0;
        for(int i = 0; i < tlength; i++)
        {
            if(j < slength && t[i] == s[j])
            {
                j++;
            }
        }
        return j == slength;
    }
};

//solution for follow-up
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slength = s.length();
        int tlength = t.length();
        //store the indexes
        vector<int> store[26];
        for(int i = 0; i < tlength; i++)
        {
            store[t[i]-'a'].push_back(i);
        }

        //keep checking for indices 
        int index = -1;
        for(int i = 0; i < slength; i++)
        {
            auto val = upper_bound(store[s[i]-'a'].begin(), store[s[i]-'a'].end(), index);
            if(val == store[s[i]-'a'].end()) return false;
            index = *val;
        }
        return true;
    }
};

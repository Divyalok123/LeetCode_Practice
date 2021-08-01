/*
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int count1[26] = {0};
        int count2[26] = {0};
        
        for(char c: s)
            count1[c-'a']++;
        
        for(char c: t)
            count2[c-'a']++;
        
        int ans = 0;
        for(int i = 0; i < 26; i++)
            if(count1[i] < count2[i])
                ans += count2[i]-count1[i];
        
        return ans;
    }
};
/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), ans = 0;
        vector<int> v(256);
        while(j < n) {
            int& t = v[s[j]];
            t++;
            
            if(t > 1) {
                while(s[i] != s[j]) v[s[i++]]--;
                i++;
                t--;
            }  
            
            if(j-i+1 > ans) ans = j-i+1;                        
            j++;
        }        
        
        return ans;
    }
};
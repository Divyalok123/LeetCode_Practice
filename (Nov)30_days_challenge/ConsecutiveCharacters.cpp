/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3518/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ans = 0, curr, i = 0;
        while(i < s.size()) {
            curr = 1;
            while(i < s.size()-1 && (s[i] == s[i+1]))
                curr++, i++;
            i++;
            if(ans < curr)
                ans = curr;
        }
        
        return ans;
    }
};
/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3461/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size()-1;
        int size = 0;
        while(j >= 0 && s[j] == ' ') j--;
        while(j >= 0)
        {
            if(s[j] == ' ')
                break;
            size++;
            j--;
        }
        return size;
    }
};
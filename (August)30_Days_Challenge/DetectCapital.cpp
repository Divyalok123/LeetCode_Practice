/*https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false;
        if(isupper(word[0])) flag = true;
        int count = flag;
        for(int i = 1; word[i]; i++) {
            if(isupper(word[i])) count++;
            if(!flag && count > 0) return false;
        }
        
        return (count==1 && flag) || count == 0 || count==word.size();
    }
};
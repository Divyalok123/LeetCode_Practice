/*https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(isupper(word[i])) count++;
        }
        
        return (count==1 && isupper(word[0])) || count == 0 || count==n;
    }
};
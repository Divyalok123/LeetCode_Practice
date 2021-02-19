/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3645/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                ans.push_back(s[i]);
                open++;
            } else if(s[i] == ')') {
                if(open) {
                     ans.push_back(s[i]);
                     open--;
                } 
            } else {
                ans.push_back(s[i]);
            }
        }
        
        n = ans.size();
        string fans = "";
        for(int i = n-1; i >= 0; i--) {
            if(ans[i] == '(' && open) open--;
            else fans.push_back(ans[i]);
        }
        
        reverse(fans.begin(), fans.end());
        return fans;
    }
};
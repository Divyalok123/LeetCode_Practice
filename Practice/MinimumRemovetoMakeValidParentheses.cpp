/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int open = 0, totalopen = 0;
        for(int i = 0; i < n; i++) {
            if(isalpha(s[i])) continue;
            
            if(s[i] == ')') {
                if(open)
                    open--;
            } else {
                open++;
                totalopen++;
            }
        }
        
        totalopen -= open;
        open = 0;
        
        string ans;
        for(int i = 0; i < n; i++) {
            if(isalpha(s[i])) {
               ans.push_back(s[i]);
            } else if (s[i] == '(') {
                if(totalopen) {
                    ans.push_back('(');
                    totalopen--;
                    open++;
                } 
            } else {
                if(open) {
                    ans.push_back(')');
                    open--;
                } 
            }
            
        }
        
        return ans;
    }
};
/*
https://leetcode.com/problems/valid-parentheses/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
    bool isopen(char c) {
        return c == '{' || (c == '(') || (c == '[');
    }
    
    bool opposite(char b, char c) {
        if(b == '{')
            return c == '}';
        if(b == '[')
            return c == ']';
        return c == ')';
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(isopen(s[i]))
                st.push(s[i]);
            else {
                if(st.empty())
                    return false;
                else if(opposite(st.top(), s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        return st.size() == 0;
    }
};
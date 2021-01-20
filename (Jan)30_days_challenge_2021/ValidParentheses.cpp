/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3610/
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isopposite(char a, char b) {
        if(a == '(') 
            return b == ')';
        else if(a == '[') 
            return b == ']';
        return b == '}';
    }
    
    bool isopen(char a) {
        return a == '[' || 
               a == '{' || 
               a == '(';
    }
    
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n&1) return 0;
        
        for(int i = 0; i < n; i++) {
            if(isopen(s[i]))
                st.push(s[i]);
            else {
                if(st.size() && isopposite(st.top(), s[i]))
                    st.pop();
                else 
                    return 0;
            }
        }
        
        return st.size() == 0;
    }
};
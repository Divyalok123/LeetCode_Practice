/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3755/
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// stack
class Solution {
public:
    int to_int(string& s) {
        int n = s.size(), i = 0, ans = 0;
        bool check = 0;
        if(s[i] == '-') check = 1, i++;
        
        while(i < n) {
            ans *= 10;
            ans += s[i++]-'0';
        }
        
        return check ? -ans : ans;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& i: tokens) {
            if(i == "+" || i == "-" || i == "*" || i == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop(); 
                
                if(i == "+") 
                    s.push(b + a);
                else if(i == "-") 
                    s.push(b - a);
                else if(i == "*") 
                    s.push(b * a);
                else 
                    s.push(b / a);
            } else
                s.push(to_int(i));
        }
        
        return s.top();
    }
};
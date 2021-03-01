/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3651/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// Solution 4 (O(1) space sol) --> Awesome solution!
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 2, res = 0, i = 1, n = S.size();
        while(i < n) {
            if(S[i] == '(')
                ans *= 2;
            else {
                ans /= 2;
                if(S[i-1] == '(') res += ans; 
            }
            i++;
        }
        
        return res;
    }
};

// SOlution 3 (Recursive - Call stack)
class Solution {
public:
    
    int help(string& s, int i, int n) { 
        if(i == n-1) return 1;
        
        int c = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == '(') c++;
            else c--;
            
            if(c == 0)
                return help(s, i, j) + help(s, j+1, n);
        }
        
        return 2*help(s, i+1, n-1);
    }
    
    int scoreOfParentheses(string S) {
        return help(S, 0, S.size()-1);
    }
};

// Solution 2 (Improved)
class Solution {
public:
    int scoreOfParentheses(string S) {
        char o = '(';
        stack<int> ss;
        ss.push(0);
        int i = 0, n = S.size();
        while(i < n) {
            if(S[i] == o) 
                ss.push(0);
            else 
            {
                int val = ss.top();
                ss.pop();
                
                val *= 2;
                if(val == 0) val++;
                
                ss.top() += val;
            }
            
            i++;
        }
        
        return ss.top();
    }
};

// Solution 1 (Stack based iterative)
class Solution {
public:
    int scoreOfParentheses(string S) {
        char o = '(', c = ')', d = '-';
        stack<char> s;
        stack<int> ss;
        
        int i = 0, n = S.size();
        while(i < n) {
            if(S[i] == o) 
            {
                s.push(o);
                ss.push(0);
            } 
            else 
            {
                int val = 0;
                while(s.size()) {
                    char t = s.top();
                    val += ss.top();
                    
                    s.pop();
                    ss.pop();
                    if(t == o) break;
                }
                
                val *= 2;
                if(val == 0) val++;
                s.push(d);
                ss.push(val);
            }
            
            i++;
        }
        
        int ans = 0;
        while(ss.size()) {
            ans += ss.top();
            ss.pop();
        }
        
        return ans;
    }
};
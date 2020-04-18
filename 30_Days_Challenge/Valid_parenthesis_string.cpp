// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

//way1 (using two stacks)
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                open.push(i);
            }
            
            if(s[i] == '*')
            {
                star.push(i);
            }
            
            if(s[i] == ')')
            {
                if(open.empty())
                {
                    if(!star.empty())
                        star.pop();
                    else 
                        return false;
                }
                
                if(!open.empty())
                {
                    open.pop();
                }
            }
        }
        
        while(!open.empty() && !star.empty())
        {
            if(star.top() < open.top()) return false;
            open.pop();
            star.pop();
        }
        
        return open.empty();
    }
};

//way 2
class Solution {
public:
    bool checkValidString(string s) {
        int opencount = 0;
        int opencounter = 0;
        
        for(int i = 0; i < s.length(); i++)
        {   
            if(s[i] == '(')
            {
                opencount++;
                opencounter++;
            }
            
            if(s[i] == ')')
            {
                opencount--;
                opencounter--;
            }
            
            if(s[i] == '*')
            {
                opencount++;
                opencounter--;
            }
            
            if(opencount < 0) return false;
            opencounter = max(opencounter, 0);
        }
        
        return opencounter == 0;
    }
};

//First try. Wrong logic
/*
class Solution {
public:
    bool checkValidString(string s) {
        if(s.length() == 0)
            return true;
        
        stack<char> st;
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ')') 
            {
                if(st.empty() && count == 0)
                {
                    return false;
                }
                
                else
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                    
                    else
                    {
                        count--;
                    }
                }
                
                if(count < 0) //just in case 
                {
                    count = 0;
                }
            }
            if(s[i] == '*')
            {
                count++;
            }
            
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            
        }
        if(!st.empty())
        {
            while(!st.empty() || count != 0)
            {
                st.pop();
                count--;
            }
            
            if(!st.empty())
            {
                return false;
            }
        }
        return true;
    }
};
*/
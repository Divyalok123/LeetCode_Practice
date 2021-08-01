/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Smarter solution - O(n) - Wormhole Principle 
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> store(n);
        int found[n];
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                store.emplace_back(i), count++;
            else if(s[i] == ')') {
                int prev = store.back();
                found[i] = prev;
                found[prev] = i;
                store.pop_back();
                count++;
            }
        }
        
        string ans(n-count, '-');
        int ind = 0;
        for(int i = 0, d = 1; i < n; i += d) {
            if(s[i] == '(' || s[i] == ')')
                d = -d, i = found[i];
            else
                ans[ind++] = s[i];
        }
        
        return ans;
    }
};

// Iteration - O(n^2)
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> lastfound;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                lastfound.emplace_back(i);
            } else if(s[i] == ')') {
                reverse(s.begin() + lastfound.back() + 1, s.begin() + i);
                lastfound.pop_back();
            }
        }
        
        string ans;
        for(char& c: s) {
            if(c == '(' || c == ')') continue;
            ans.push_back(c);
        }
        
        return ans;
    }
};

// Recursion - O(n^2)
class Solution {
public:
    vector<int> ends;
    
    string helper(string& s, int i, int j) {
        string ans;
        for(int k = i; k <= j; k++) {
            if(s[k] == '(') {
                ans += helper(s, k+1, ends[k]-1);
                k = ends[k];
            } else {
                ans.push_back(s[k]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string reverseParentheses(string s) {
        int n = s.size();
        ends.resize(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') 
                st.push(i);
            else if(s[i] == ')') {
                ends[st.top()] = i;
                st.pop();
            }
        }
        
        string ans;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                ans += helper(s, i+1, ends[i]-1);
                i = ends[i];
            } else {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
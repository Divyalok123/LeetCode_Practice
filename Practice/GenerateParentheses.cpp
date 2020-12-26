/*
https://leetcode.com/problems/generate-parentheses/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void helper(int n, int cl, int op, string& s) {
        if(cl + op == 2*n) {
            if(s != "") 
                ans.push_back(s);
            return;
        }
        
        if(cl != n) {
            s.push_back('(');
            helper(n, cl+1, op, s);
            s.pop_back();
        }
        
        if(op != n && op < cl) {
            s.push_back(')');
            helper(n, cl, op+1, s);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        
        string s = "";
        helper(n, 0, 0, s);
        return ans;
    }
};
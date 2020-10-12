/*
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std; 

class Solution {
public:
    string smallestSubsequence(string s) {
        if(s.size()==1)
            return s;
        
        int i = 0, buck[26] = {0};
        for(char& c: s)
            buck[c-'a']++;
        
        bool check[26] = {0};
        stack<char> ss;
        
        for(i = 0; i < s.size(); i++) {
            if(!check[s[i]-'a']) {
                while(!ss.empty() && (ss.top() > s[i]) && (buck[ss.top()-'a'])) {
                    check[ss.top()-'a'] = 0;
                    ss.pop();
                }                
                ss.push(s[i]);
                check[s[i]-'a'] = 1;
            }
            buck[s[i]-'a']--;
        }
        
        i = 0;
        string ans(ss.size(), '-');
        while(!ss.empty()) {
            ans[i++] = ss.top();
            ss.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
https://leetcode.com/problems/shortest-palindrome/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string ns = s;
        reverse(ns.begin(), ns.end());
        
        s += "?" + ns;
        
        //finding lps of s;
        
        // cout << "finding lps" << endl;
        
        int n = s.size();
        vector<int> lps(n);
        
        int j = 1, c = 0;
        lps[0] = 0;
        
        while(j < n) {
            if(s[j] == s[c]) {
                c++;
                lps[j] = c;
                j++;
            } else {
                if(c == 0) {
                    lps[j] = 0;
                    j++;
                } else {
                    c = lps[c-1];
                }
            }
        }
        
        // cout << "LPS" << endl;
        // for(int& i: lps)
            // cout << i << " ";
        // cout << endl;
        
        string st;
        int similar = ns.size()-lps.back();
        // cout << "similar: " << similar << endl;
        for(int i = 0; similar; i++)
            st.push_back(ns[i]), similar--;
        reverse(st.begin(), st.end());
        ns += st;
        return ns;
    }
};
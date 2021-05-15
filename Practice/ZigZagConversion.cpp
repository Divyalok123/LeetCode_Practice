/*
https://leetcode.com/problems/zigzag-conversion/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        
        vector<string> v(n);
        int i = 0, sz = s.size(), r = 0, up = 0;
        
        while(i < sz) {
            if(up) 
                v[r--].push_back(s[i++]);
            else 
                v[r++].push_back(s[i++]);
            
            if(r == -1) 
                r = 1, up = 0;
            else if(r == n) 
                r = n-2, up = 1;
        }
        
        string ans;
        
        for(auto& ss: v) 
            ans += ss;
        
        return ans;
    }
};
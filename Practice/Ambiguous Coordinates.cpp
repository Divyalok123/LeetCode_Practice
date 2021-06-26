/*
https://leetcode.com/problems/ambiguous-coordinates/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void gett(vector<string>& vec, string&& s) {
        int n = s.size();
        if(n == 1) 
            vec = {s};
        
        else if(s.front() == '0') {
            if(s.back() != '0') 
                vec = {("0." + s.substr(1))};
        } 
        
        else if(s.back() == '0')
            vec = {s};
        
        else {
            vec = {s};
            for(int i = 1; i < n; i++)
                vec.push_back(s.substr(0, i) + "." + s.substr(i));
        }

    }
    
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        int n = s.size();
        
        for(int i = 1; i < n-2; i++) {
            vector<string> a, b;
            gett(a, s.substr(1, i));
            
            if(a.size() == 0) continue;
            
            gett(b, s.substr(i+1, n-2-i));
            
            if(b.size() == 0) continue;
            
            for(auto& j: a)
                for(auto& k: b)
                    ans.push_back("(" + j + ", " + k + ")");
        }
        
        return ans;
    }
};
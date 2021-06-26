/*
https://leetcode.com/problems/find-and-replace-pattern/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool samePattern(string& s, string& t) {
        int n = s.size();;
        unordered_map<char, char> um;
        unordered_map<char, char> umm;
        for(int i = 0; i < n; i++) {
            if(um.count(t[i])) {
                if(um[t[i]] != s[i]) 
                    return false;
            } else if(umm.count(s[i])) {
                if(umm[s[i]] != t[i]) 
                    return false;
            } else {
                if(umm.count(s[i]) == 0 && um.count(t[i]) == 0)
                    umm[s[i]] = t[i], um[t[i]] = s[i];
                else 
                    umm.count(s[i]) ? um[t[i]] = s[i] : umm[s[i]] = t[i];
            }
            
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int m = pattern.size();
        vector<string> ans;
        for(auto& j: words) {
            if(m == j.size() && samePattern(j, pattern))
                ans.push_back(j);
        }
        
        return ans;
    }
};
/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3565/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* Improvisation */
class Solution {
public:
    bool ispalin(string& s) {
        int i = 0, j = s.size()-1;
        while(i < j)
            if(s[i++] != s[j--])
                return 0;
        return 1;
    }
    
    void move(string& s, vector<vector<string>>& ans, vector<string>& v, int start) {
        if(start == s.size()) {
            ans.push_back(v); 
            return;
        }

        string thiss;
        for(int i = start; i < s.size(); i++) {
            thiss+=s[i]; //improved here
            if(ispalin(thiss)) {
                v.push_back(thiss);
                move(s, ans, v, i+1);
                v.pop_back();
                        
            }
        }
        
    }
    
    vector<vector<string>> partition(string ss) {
        int n = ss.size();
        if(n == 1)
            return {{ss}};
        
        vector<vector<string>> ans;
        vector<string> cont;
        move(ss, ans, cont, 0);
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    
    bool ispalin(string& s, int i, int j) {
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    
    void move(string& s, vector<vector<string>>& ans, vector<string>& v, int start) {
        if(start == s.size()) {
            ans.push_back(v); 
            return;
        }
        
        string thiss;
        for(int i = start; i < s.size(); i++) {
            if(ispalin(s, start, i)) {
                v.push_back(s.substr(start, i-start+1));
                move(s, ans, v, i+1);
                v.pop_back();
                        
            }
        }
        
    }
    
    vector<vector<string>> partition(string ss) {
        int n = ss.size();
        if(n == 1)
            return {{ss}};
        
        vector<vector<string>> ans;
        vector<string> cont;
        move(ss, ans, cont, 0);
        return ans;
    }
};
/*
https://leetcode.com/problems/reorder-data-in-log-files/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkdigit(string& s)
    {
        int i = 0;
        while(i < s.size() && s[i] != ' ') 
            i++;
        i++;
        if(isalpha(s[i]))
            return false;
        return true;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans1, ans2;
        for(auto& a: logs) {
            if(!checkdigit(a))
                ans1.push_back(a);
            else 
                ans2.push_back(a);
        }
        
        sort(ans1.begin(), ans1.end(), [](const string& a, const string& b){
            
            int i1 = a.find(' ');
            int i2 = b.find(' ');
            
            string a1 = a.substr(0,i1);
            string a2 = a.substr(i1+1);
            string b1 = b.substr(0,i2);
            string b2 = b.substr(i2+1);
            return (a2 < b2) || (a2 == b2 && a1 < b1);
        });
        
        for(auto& a: ans2)
            ans1.push_back(a);
        
        return ans1;
    }
};
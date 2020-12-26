/*
https://leetcode.com/problems/minimum-window-substring/
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/* Better */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(123);
        for(char& c: t)
            v[c]++;
        
        int min = INT_MAX;
        
        int ansi = -1, count = 0, finalc = INT_MAX;
        int i = 0, j = 0, sz = s.size(), tz = t.size();
        while(j < sz) {
            if(--v[s[j++]] >= 0) count++;
            while(count == tz) {
                if(j-i < finalc) { 
                    finalc = j-i;
                    ansi = i;
                }
                v[s[i]]++;
                if(v[s[i]] > 0) count--;
                i++;
            }
        } 
        
        return ansi == -1 ? "" : s.substr(ansi, finalc);
    }
};

/* Solution 1 */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v1(150);
        vector<int> v2(150);
        
        for(char& c: t)
            v1[c]++;
        
        string ans;
        int min = INT_MAX;
        
        int ansi = -1, count = INT_MAX;
        int i = 0, j = 0, sz = s.size(), tz = t.size(), uniquecount = 0;
        while(j < sz) {
            if(uniquecount == tz) {
                if(count > j-i) {
                    count = j-i;
                    ansi = i;
                }
                v2[s[i]]--;
                if(v2[s[i]] < v1[s[i]]) uniquecount--;
                i++;
            } else {
                v2[s[j]]++;
                if(v2[s[j]] <= v1[s[j]]) uniquecount++;
                j++;
            }
        } 
        
        while(uniquecount == tz && i < sz) {
            v2[s[i]]--;
            if(v2[s[i]] < v1[s[i]]) uniquecount--;
            i++;
        }
        
        if(count > j-i+1) ansi = i-1;
        return ansi == -1 ? "" : s.substr(ansi, count);
    }
};
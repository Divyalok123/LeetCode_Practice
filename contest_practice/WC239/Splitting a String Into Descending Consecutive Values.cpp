/*
https://leetcode.com/contest/weekly-contest-239/problems/splitting-a-string-into-descending-consecutive-values/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool splitString(string s, int i = 0, unsigned long long pre = -1, int preind = 0, bool check = true) {
        if(i == s.size()) 
            return pre != -1 && preind != 0;
        
        unsigned long long val = 0;
        bool ans = 0;
        preind = i;
        if(check == 1) {
            while(i < s.size() && s[i] == '0')
                i++;
        }
        
        int len = (check ? (s.size()-i)/2 : s.size());
        int dist = min(i+len+1, (int)s.size());
        for(int j = i; j < dist; j++) {
            val = val*10 + 0ull + (s[j]-'0');
            if(pre == -1 || val == pre-1)
                ans = ans || splitString(s, j+1, val, preind, false);
        }
        
        return ans;
    }
};

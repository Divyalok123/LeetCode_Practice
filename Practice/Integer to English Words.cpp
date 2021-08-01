/*
https://leetcode.com/problems/integer-to-english-words/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string store1[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string store2[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string store3[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string store4[3] = {"Thousand", "Million", "Billion"};
    
    string getvalue(string& num) {
        int sz = num.size();
        string ans;
        if(sz == 3 && num[0] != '0')
            ans += store1[num[0]-'0'-1] + " Hundred";
        
        if(sz >= 2 && num[sz-2] != '0')
        {
            if(num[sz-2] == '1') return ans + (ans.size() ? " " : "") + store2[num[sz-1]-'0'];
            else ans +=  (ans.size() ? " " : "") + store3[num[sz-2]-'0'-2];
        }
        
        if(num[sz-1] != '0')
            ans += (ans.size() ? " " : "") + store1[num[sz-1]-'0'-1];
        
        return ans;
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        string s = to_string(num);
        int sz = s.size();
        vector<string> vec;
        
        int i = sz-1, count = 0;
        string t;
        while(i >= 0) {
            t.push_back(s[i]);
            i--;
            count++;
            
            if(count == 3 || i == -1) {
                reverse(t.begin(), t.end());
                vec.push_back(t);
                t = "";
                count = 0;
            }
        }
        
        string ans;
        
        for(int j = 4; j >= 2; j--) {
            if(vec.size() < j) continue;
            string f = vec.back();
            vec.pop_back();
            
            string val = getvalue(f);
            if(val.size())
                ans += (ans.size() ? " " : "") + val + " " + store4[j-2];
        }
             
        string val = getvalue(vec.back());
        if(val.size())
            ans += (ans.size() ? " " : "") + val;
        return ans;
    }
};
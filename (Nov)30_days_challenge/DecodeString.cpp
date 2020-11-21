/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3536/
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/* Iterative Solution */
class Solution {
public:
    string decodeString(string s) {
        if(s.size() <= 3)
            return s;
        vector<string> v;
        string ans, temp, temp1;
        int i = 0, n = s.size();
        
        while(i < n) {
            if(s[i] == ']') {
                ans = "";
                while(v.size() && isalpha(v.back()[0]))
                {
                    ans = v.back() + ans; //bad step..
                    v.pop_back();
                }
                
                if(v.size()) {
                    int x = stoi(v.back());
                    temp = "";
                    v.pop_back();
                    for(int j = 0; j < x; j++)
                        temp += ans;
                    v.push_back(temp);
                }
                i++;
            }
            
            temp = "";
            temp1 = "";
            while(i < n && isalpha(s[i]))
                temp.push_back(s[i++]);
            if(temp.size())
                v.push_back(temp);
            while(i < n && isdigit(s[i]))
                temp1.push_back(s[i++]);
            if(temp1.size())
                i++, v.push_back(temp1);
        }

        ans.clear();
        for(auto& ss: v)
            ans += ss;
        
        return ans;
    }
};

/* Recursive solution */
class Solution
{
public:
    int i = 0;
    string helper(string &s)
    {
        if (i >= s.size() || s[i] == ']')
            return "";

        string ans, temp, temp2;
        while (i < s.size())
        {
            while (i < s.size() && isalpha(s[i]))
                ans.push_back(s[i++]);

            temp = "";
            int n = 0;
            while (i < s.size() && isdigit(s[i]))
                temp.push_back(s[i++]);

            if (temp.size() > 0)
                n = stoi(temp);

            if (i < s.size() && s[i] == '[' && n)
            {
                i++;
                temp2 = helper(s);
                for (int j = 0; j < n; j++)
                    ans += temp2;
            }

            if (i < s.size() && s[i] == ']')
            {
                i++;
                return ans;
            }
        }

        return ans;
    }

    string decodeString(string s)
    {
        if (s.size() <= 3)
            return s;
        i = 0;
        return helper(s);
    }
};
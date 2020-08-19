/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string toGoatLatin(string S)
    {
        string ans = "";

        bool flag = false;
        char prev = ' ';
        char held = '-';
        string as = "a";
        for (char c : S)
        {
            if (c != ' ' && !isVowel(c) && prev == ' ')
            {
                flag = true;
                held = c;
                prev = c;
                continue;
            }

            if (c == ' ')
            {
                if (flag)
                {
                    if (held != '-')
                        ans += held;
                    held = '-';
                    flag = false;
                }
                ans += "ma";
                ans += as;
                as += 'a';
                ans += " ";
                prev = ' ';
                continue;
            }

            ans += c;
            prev = c;
        }

        if (flag && held != '-')
        {
            ans += held;
        }
        ans += "ma";
        ans += as;
        return ans;
    }
};
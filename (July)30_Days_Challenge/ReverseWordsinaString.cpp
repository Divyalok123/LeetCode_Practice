/* Given an input string, reverse the string word by word. */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int size = s.size();
        if (size == 0)
            return s;

        while (size != 0 && s.back() == ' ')
        {
            s.pop_back();
            size--;
        }

        if (size == 0)
            return s;

        int i = 0;
        int j = s.length() - 1;

        string o;
        while (s[i] == ' ')
        {
            i++;
        }

        for (; i <= j; i++)
        {
            if (s[i] == ' ')
            {
                o.push_back(' ');
                while (s[i] == ' ')
                    i++;
                i--;
            }
            else
                o.push_back(s[i]);
        }

        int prev = -1;
        i = 0;
        j = o.size() - 1;

        reverse(o.begin(), o.end());

        for (i = 0; i <= j; i++)
        {
            if (o[i] == ' ')
            {
                reverse(o.begin() + prev + 1, o.begin() + i);
                prev = i;
            }

            else if (i == j)
            {
                reverse(o.begin() + prev + 1, o.begin() + j + 1);
            }
        }

        return o;
    }
};
/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3629/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string ans;
        int n = path.size(), i = 0;
        while (i < n)
        {
            if (path[i] == '/')
            {
                if (ans.size())
                {
                    if (ans.back() != '/')
                        ans.push_back('/');
                }
                else
                    ans.push_back('/');

                i++;
                while (i < n && path[i] == '/')
                    i++;
            }
            else if (path[i] == '.')
            {

                int c = 0;
                while (i < n && path[i] == '.')
                    c++, i++;

                if (i == n || (i < n && path[i] == '/'))
                {
                    if (c == 2)
                    {
                        if (ans.size() - 1)
                            ans.pop_back();
                        while (ans.size() && ans.back() != '/')
                            ans.pop_back();
                    }
                    else if(c > 2)
                    {
                        while (c--)
                            ans.push_back('.');
                    }
                }
                else
                {
                    while (c--)
                        ans.push_back('.');
                }
            }
            else
            {
                while (i < n && path[i] != '/')
                    ans.push_back(path[i++]);
            }
        }

        while (ans.size() - 1 && ans.back() == '/')
            ans.pop_back();

        return ans;
    }
};
/*
https://leetcode.com/problems/basic-calculator/
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int res = 0;
        int curr = 0;
        int sg = 1;
        vector<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
                continue;
            if (isdigit(s[i]))
                curr = curr * 10 + (s[i] - '0');
            else if (s[i] == '+' || s[i] == '-')
            {
                res += curr * sg;
                curr = 0;
                sg = s[i] == '+' ? 1 : -1;
            }
            else if (s[i] == '(')
            {
                st.push_back(res);
                st.push_back(sg);
                res = 0, sg = 1;
            }
            else
            {
                res += sg * curr;
                curr = 0;

                res *= st.back();
                st.pop_back();

                res += st.back();
                st.pop_back();
            }
        }

        res += sg * curr;
        return res;
    }
};

/* Solution 1 */
class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int ans = 0, curr = 0;
        string t, tp;
        stack<string> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] != ')')
            {
                tp = "";
                if (!isdigit(s[i]))
                {
                    tp.push_back(s[i]);
                    st.push(tp);
                }
                else
                {
                    while (i < n && isdigit(s[i]))
                        tp.push_back(s[i++]);
                    st.push(tp);
                    i--;
                }
            }
            else
            {
                curr = 0;
                ans = 0;
                while (!st.empty() && st.top() != "(")
                {
                    t = st.top();
                    st.pop();
                    if (t == "+")
                        ans += curr;
                    else if (t == "-")
                        ans -= curr;
                    else
                        curr = stoi(t);
                }
                ans += curr;
                st.pop();
                st.push(to_string(ans));
            }
        }

        curr = 0;
        ans = 0;
        while (!st.empty())
        {
            t = st.top();
            st.pop();
            if (t == "+")
                ans += curr;
            else if (t == "-")
                ans -= curr;
            else
                curr = stoi(t);
        }

        ans += curr;
        return ans;
    }
};
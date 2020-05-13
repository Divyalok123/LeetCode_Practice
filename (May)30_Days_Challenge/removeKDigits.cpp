
// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.length() == k)
        {
            return "0";
        }

        stack<int> s;
        s.push(num[0]);

        for (int i = 1; i < num.length(); i++)
        {
            while (!s.empty() && k != 0 && (s.top() > num[i]))
            {
                s.pop();
                k--;
            }

            s.push(num[i]);
        }

        if (k != 0)
        {
            while (k != 0 && !s.empty())
            {
                s.pop();
                k--;
            }
        }

        string ans = "";

        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (ans[0] == '0')
        {
            ans.erase(0, 1);
        }
        return ans.length() == 0 ? "0" : ans;
    }
};

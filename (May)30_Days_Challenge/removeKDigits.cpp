
// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.

#include <iostream>
#include <string>
// #include <stack>
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
        string ans = "";
        ans.push_back(num[0]);

        for (int i = 1; i < num.length(); i++)
        {
            while (ans.length() && k != 0 && (ans.back() > num[i]))
            {
                ans.pop_back();
                k--;
            }
            if(ans.length() || num[i] != '0') ans.push_back(num[i]);
        }

        while (k != 0 && ans.length())
        {
            ans.pop_back();
            k--;
        }

        // while (ans[0] == '0')
        // {
        //     ans.erase(0, 1);
        // }
        return ans.length() == 0 ? "0" : ans;
    }
};

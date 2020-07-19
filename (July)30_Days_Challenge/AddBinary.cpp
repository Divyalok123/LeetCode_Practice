// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0, sum;
        string ans = "";

        int l1 = a.size() - 1, l2 = b.size() - 1;
        while (l1 >= 0 || l2 >= 0)
        {
            sum = carry;

            if (l1 >= 0)
                sum += (a[l1] - '0'), l1--;

            if (l2 >= 0)
                sum += (b[l2] - '0'), l2--;

            ans.push_back(sum % 2 + '0');
            carry = sum / 2;
        }

        if (carry == 1)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
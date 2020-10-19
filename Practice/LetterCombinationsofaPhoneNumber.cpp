/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> store = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution
{
public:
    void solve(string &digit, int i, string &g, vector<string> &ans)
    {
        if (i == digit.size())
        {
            if (g != "")
                ans.push_back(g);
            return;
        }
        string curr = store[digit[i] - '1'];
        for (int k = 0; k < curr.size(); k++)
        {
            g.push_back(curr[k]);
            solve(digit, i + 1, g, ans);
            g.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string temp;
        solve(digits, 0, temp, ans);
        return ans;
    }
};
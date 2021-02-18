/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3642/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<string> &ans, string &S, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(S);
            return;
        }

        dfs(ans, S, i + 1, n);
        if (isalpha(S[i]))
        {
            if (isupper(S[i]))
                S[i] = tolower(S[i]);
            else
                S[i] = toupper(S[i]);

            dfs(ans, S, i + 1, n);
        }
    }

    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        int sz = S.size();
        dfs(ans, S, 0, sz);
        return ans;
    }
};
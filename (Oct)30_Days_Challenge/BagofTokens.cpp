/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3506/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int p)
    {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if (n == 0 || p < tokens[0])
            return 0;

        int i = 0, ans = 0, maxans = 0, j = n - 1;
        while (i <= j)
        {
            if (p >= tokens[i])
            {
                p -= tokens[i++], ans++;
                maxans = max(maxans, ans);
            }
            else if (ans >= 1)
                p += tokens[j--], ans--;
            else
                break;
        }

        return maxans;
    }
};
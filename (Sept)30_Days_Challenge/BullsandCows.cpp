/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3455/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        vector<int> v(10, 0);
        for (auto &a : secret)
            v[a - '0']++;

        int cows = 0;
        for (auto &a : guess)
            if (v[a - '0'])
                v[a - '0']--, cows++;

        int bulls = 0;
        for (int i = 0; i < secret.size(); i++)
            if (secret[i] == guess[i])
                bulls++;

        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
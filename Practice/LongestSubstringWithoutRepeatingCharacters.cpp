/* https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> mapp;
        int count = 0;
        int l = 1, r = 1;
        for (int i = 1; i <= s.length(); i++)
        {
            if (l < mapp[s[i - 1]] + 1)
            {
                l = mapp[s[i - 1]] + 1;
            }

            mapp[s[i - 1]] = i;
            r = i;

            if (r - l + 1 > count)
            {
                count = r - l + 1;
            }
        }

        return count;
    }
};
/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/

/* https://leetcode.com/problems/word-break/ */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    unordered_map<string, vector<string>> _m;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        if (_m.count(s))
            return _m[s];
        vector<string> ans;
        if (s.size() == 0)
        {
            ans.push_back("");
            return ans;
        }
        for (string d : wordDict)
        {
            string w = s.substr(0, d.length());
            if (w.compare(d) == 0)
            {
                vector<string> v;
                v = wordBreak(s.substr(d.length()), wordDict);
                for (string a : v)
                {
                    ans.push_back(w + (a.size() == 0 ? "" : " ") + a);
                }
            }
        }

        _m[s] = ans;
        return ans;
    }
};
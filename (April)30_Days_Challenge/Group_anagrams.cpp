// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> output;
        map<string, vector<string>> mymap;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            string s = temp;
            sort(temp.begin(), temp.end());
            mymap[temp].push_back(s);
        }

        map<string, vector<string>>::iterator it = mymap.begin();
        while (it != mymap.end())
        {
            output.push_back(it->second);
            it++;
        }
        return output;
    }
};
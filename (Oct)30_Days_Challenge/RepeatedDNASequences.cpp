/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3498/
*/

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* Solution 3 (converting string to 4-byte int instead of hashing or storing string: both accurate and memory efficient)*/
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 11)
            return {};

        unordered_set<int> us;
        unordered_set<int> us2;
        int mm[26] = {0};
        vector<string> ans;

        mm['C' - 'A'] = 1;
        mm['G' - 'A'] = 2;
        mm['T' - 'A'] = 3;

        int val = 0;
        //generating the value for first 10 chars
        for (int i = 0; i < 10; i++)
        {
            val <<= 2;
            val |= mm[s[i] - 'A'];
        }
        us.insert(val);

        //sliding
        for (int i = 10; i < s.size(); i++)
        {
            val &= ~(3 << 18); //11 -> 11000000000000000000 -> 00111111111111111111 -> getting last 18 bits of val
            val <<= 2; //shifting right
            val |= mm[s[i] - 'A']; //adding the current alph
            if (us.find(val) == us.end())
                us.insert(val);
            else if (us2.find(val) == us2.end())
            {
                us2.insert(val);
                ans.push_back(s.substr(i - 9, 10));
            }
        }
        return ans;
    }
};

/* Solution 2 (litle faster but not accurate as hashes may collide) */
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 11)
            return {};

        unordered_map<size_t, int> umap2;
        vector<string> ans;
        size_t val;
        string ss;
        for (int i = 0; i < s.size() - 9; i++)
        {
            ss = s.substr(i, 10);
            val = hash<string>{}(ss);
            umap2[val]++;
            if (umap2[val] == 2)
            {
                ans.push_back(ss);
            }
        }

        return ans;
    }
};

/* Solution 1 (too much memory consumption and memory limit may get exceeded)*/
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 11)
            return {};
        unordered_map<string, int> umap;
        vector<string> ans;
        string ss;
        for (int i = 0; i < s.size() - 9; i++)
        {
            ss = s.substr(i, 10);
            umap[ss]++;
            if (umap[ss] == 2)
            {
                ans.push_back(ss);
            }
        }
        return ans;
    }
};
/*
https://leetcode.com/problems/text-justification/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int k)
    {
        if (words.size() == 0)
            return words;

        if (words.size() == 1)
        {
            int diff = k - words[0].size();
            for (int i = 0; i < diff; i++)
                words[0] += " ";
            return words;
        }

        int n = words.size();
        vector<string> ans;
        vector<string> temp;
        string ss;
        int i = 0, s, t, d, diff;
        while (i < n)
        {
            s = 0;
            temp.resize(0);
            s += words[i].size();
            temp.push_back(words[i++]);
            while (i < n && ((s + words[i].size() + 1) <= k))
            {
                s += words[i].size() + 1;
                temp.push_back(words[i]);
                i++;
            }
            ss = "";
            s = k - s;
            if (i == n)
            {
                ss += temp[0];
                for (int l = 1; l < temp.size(); l++)
                    ss += " " + temp[l];
                for (int m = 0; m < s; m++)
                    ss += " ";
                ans.push_back(ss);
                continue;
            }

            if (temp.size() == 1)
            {
                ss += temp[0];
                for (int l = 0; l < k - temp[0].size(); l++)
                    ss += " ";
                ans.push_back(ss);
                continue;
            }

            t = temp.size() - 1;
            d = s / t;
            diff = s % t;
            ss += temp[0];

            for (int l = 1; l < temp.size(); l++)
            {
                ss += " ";
                for (int m = 0; m < d; m++)
                    ss += " ";
                if (diff)
                {
                    ss += " ";
                    diff--;
                }
                ss += temp[l];
            }
            ans.push_back(ss);
        }

        return ans;
    }
};

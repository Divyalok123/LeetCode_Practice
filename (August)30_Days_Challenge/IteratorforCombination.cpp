/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//solution 2
class CombinationIterator
{
    string s;
    int n, l;
    vector<int> v;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        n = combinationLength;
        l = characters.length();
        s = characters;
        v.resize(n);
        for (int i = 0; i < n; i++)
            v[i] = i;
    }
    int count = 0;
    string next()
    {
        string ans = "";
        if (count == 0)
        {
            for (int i = 0; i < n; i++)
                ans += s[i];
            count = 1;
            return ans;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] != l - n + i)
            {
                v[i] += 1;
                for (int j = i + 1; j < n; j++)
                {
                    v[j] = v[i] + j - i;
                }
                break;
            }
        }
        for (int i = 0; i < n; i++)
            ans += s[v[i]];
        return ans;
    }

    bool hasNext()
    {
        return v[0] != l - n;
    }
};

//solution 1
class CombinationIterator
{
    queue<string> q;

public:
    void getCombinations(string &c, int k, int i, string temp)
    {
        if (k == 0)
        {
            q.push(temp);
            return;
        }

        for (int j = i; j < c.length() - k + 1; j++)
        {
            getCombinations(c, k - 1, j + 1, temp + c[j]);
        }
    }

    CombinationIterator(string characters, int combinationLength)
    {
        getCombinations(characters, combinationLength, 0, "");
    }

    string next()
    {
        string ans = q.front();
        q.pop();
        return ans;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};

/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//solution 2


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

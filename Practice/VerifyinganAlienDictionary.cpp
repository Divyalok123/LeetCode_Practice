/*
https://leetcode.com/problems/verifying-an-alien-dictionary/
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> umap;
    bool check(string &a, string &b)
    {
        int i;
        for (i = 0; i < min(a.size(), b.size()); i++)
        {
            if (umap[a[i]] != umap[b[i]])
            {
                if (umap[a[i]] <= umap[b[i]])
                    return true;
                else
                    return false;
            }
        }

        if (i < a.size())
            return false;
        return true;
    }

    bool isAlienSorted(vector<string> &word, string order)
    {
        if (word.size() <= 1)
            return true;

        for (int i = 0; i < order.size(); i++)
            umap[order[i]] = i + 1;

        for (int i = 0; i < word.size() - 1; i++)
        {
            // cout << "iterator " << i << endl;
            if (!check(word[i], word[i + 1]))
                return false;
        }

        return true;
    }
};
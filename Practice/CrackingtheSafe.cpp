/*
https://leetcode.com/problems/cracking-the-safe/
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> umap;

    void helper(int i, int n, int k, string &s)
    {
        if (i == n - 1)
        {
            umap[s] = k;
            return;
        }

        for (int j = 0; j < k; j++)
        {
            s.push_back(j + '0');
            helper(i + 1, n, k, s);
            s.pop_back();
        }
    }

    void helper2(string &s, int n, int lim)
    {

        for (int i = 0; i < n; i++)
            s += "0";

        // umap[s.substr(0, n-1)].pop_front();
        // cout << "i: 0 " << "s: " << s << endl;

        string temp;
        for (int i = n; i < lim; i++)
        {

            temp = s.substr(s.size() - n + 1, n - 1);
            char c;
            int &l = umap[temp];
            c = (--l) + '0';
            // l.pop_back();

            s.push_back(c);
            // cout << "i: " << i-n+1 << " s: " << s << endl;
        }
    }

    string crackSafe(int n, int k)
    {
        //handling n==1 separately
        if (n == 1)
        {
            string ans;
            for (int i = 0; i < k; i++)
                ans.push_back(i + '0');
            return ans;
        }

        //getting all possible string of length n-1
        string s;
        helper(0, n, k, s);

        //final answer will be of size k^n + (n-1)

        //getting the power
        int pow = 1, t = n, v = k;
        while (t)
        {
            if (t & 1)
                pow *= v;
            v *= v;
            t >>= 1;
        }

        pow += (n - 1);
        string ans;

        //making the final string
        helper2(ans, n, pow);

        return ans;
    }
};
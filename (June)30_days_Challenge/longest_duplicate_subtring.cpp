/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
    const int mod = 1e7 + 9;
    const int p = 31;

public:
    int m_inverse(int n, int m)
    {
        int temp = m;
        int y = 0, x = 1;

        if (m == 1)
            return 0;

        while (n > 1)
        {
            int q = n / m;
            int t = m;

            m = n % m;
            n = t;

            t = y;
            y = x - (q)*y;
            x = t;
        }

        if (x < 0)
            x += temp;

        return x;
    }

    bool helper(string &s, int len, vector<int> &power, string &ans, int l, vector<int> &hash, vector<int> &inv)
    {
        unordered_map<int, vector<int>> mapp;

        mapp[(hash[l] + mod) % mod].push_back(0);
        for (int i = 1; i < len - l + 1; i++)
        {
            int newval = (hash[i + l] - hash[i] + mod) % mod;
            newval = (int)(((long long)((long long)newval * (long long)inv[i])) % (long long)mod);

            if (mapp.find(newval) != mapp.end())
                for (auto x : mapp[newval])
                {
                    string one = s.substr(x, l);
                    string sec = s.substr(i, l);
                    if (one.compare(sec) == 0)
                    {
                        ans = one;
                        return true;
                    }
                }
            mapp[newval].push_back(i);
        }

        return false;
    }

    string longestDupSubstring(string S)
    {

        int len = S.length();

        if (len == 0)
            return "";

        vector<int> power(len);
        power[0] = 1;
        for (int i = 1; i < len; i++)
        {
            power[i] = (power[i - 1] * p) % mod;
        }

        vector<int> inverses(len);
        for (int i = 0; i < len; i++)
        {
            inverses[i] = m_inverse(power[i], mod);
        }

        vector<int> hash(len + 1, 0);
        for (int i = 0; i < len; i++)
        {
            hash[i + 1] = (hash[i] + (S[i] - 'a' + 1) * power[i]) % mod;
        }

        int l = 1, r = len;
        string ans = "";
        while (l <= r)
        {
            string temp = "";
            int m = l + (r - l) / 2;
            bool check = helper(S, len, power, temp, m, hash, inverses);
            if (check)
            {
                if (temp.size() > ans.size())
                    ans = temp;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        return ans;
    }
};
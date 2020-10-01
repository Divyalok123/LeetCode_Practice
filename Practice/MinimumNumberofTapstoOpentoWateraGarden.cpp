/*
https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*--- Method 2 ---*/
class Solution
{
public:
    int minTaps(int m, vector<int> &ranges)
    {
        int n = ranges.size();
        if (n <= 1)
            return n;
        int l, r;
        vector<int> v(n);
        for (int i = 0; i < ranges.size(); i++)
        {
            l = max(0, i - ranges[i]);
            r = min(n - 1, i + ranges[i]);
            v[l] = max(v[l], r - l);
        }

        int curr = 0, prev = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > prev)
            {
                count++;
                if (curr <= prev)
                    return -1;
                prev = curr;

                if (curr == n - 1)
                    return count;
            }
            curr = max(curr, v[i] + i);
        }

        return -1;
    }
};

/*--- Method 1 ---*/
class Solution
{
public:
    int minTaps(int m, vector<int> &ranges)
    {
        int n = ranges.size();
        if (n <= 1)
            return n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = make_pair(max(0, i - ranges[i]), min(n - 1, i + ranges[i]));

        sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first < b.first) || ((a.first == b.first) && (a.second < b.second));
        });

        int i = 0, count = 0, maxright = 0, val = 0;
        while (val < n)
        {
            if (maxright == n - 1)
                return count;
            while (i < n && v[i].first <= val)
            {
                maxright = max(maxright, v[i].second);
                i++;
            }

            if (maxright == val)
                return -1;
            count++;
            val = maxright;
        }
        return count;
    }
};

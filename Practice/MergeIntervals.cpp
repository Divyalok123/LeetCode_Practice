/*
https://leetcode.com/problems/merge-intervals/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || ((a[0] == b[0]) && a[1] < b[1]);
        });

        int i = 0, n = intervals.size(), j;
        vector<int> v;
        while (i < n)
        {
            v = intervals[i];
            j = i + 1;

            while (j < n && (intervals[j][0] <= v[1]))
            {
                v[0] = min(v[0], intervals[j][0]);
                v[1] = max(v[1], intervals[j][1]);
                j++;
            }

            ans.push_back(v);
            i = j;
        }
        return ans;
    }
};
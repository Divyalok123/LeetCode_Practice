/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3483/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &in)
    {
        if (in.size() == 1)
            return 1;
        sort(in.begin(), in.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int held = in[0][1];
        int ans = in.size();
        for (int i = 1; i < in.size(); i++)
        {
            if (in[i][1] > held)
                held = in[i][1];
            else
                ans--;
        }
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        stack<pair<int, int>> s;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        for (int i = 0; i < intervals.size(); i++)
        {
            while (!s.empty() && ((s.top().first >= intervals[i][0]) && (s.top().second <= intervals[i][1])))
                s.pop();
            s.push({intervals[i][0], intervals[i][1]});
        }
        return s.size();
    }
};
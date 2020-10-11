/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3490/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() <= 1)
            return points.size();

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[1] < b[1]) || ((a[1] == b[1]) && a[0] < b[0]);
        });
        int n = points.size();

        int j, count = 0, i = 0;
        while (i < n)
        {
            j = i + 1;
            while (j < n && (points[j][0] <= points[i][1]))
                j++;
            i = j;
            count++;
        }
        return count;
    }
};
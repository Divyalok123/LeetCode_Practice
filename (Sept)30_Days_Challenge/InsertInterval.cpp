/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3458/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) 
            return {newInterval};
        
        vector<vector<int>> v;
        int i;
        for(i = 0; i < intervals.size() && intervals[i][1] < newInterval[0]; i++)
            v.push_back(intervals[i]);
        for(; i < intervals.size() && intervals[i][0] <= newInterval[1]; i++)
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
        }
        
        v.push_back(newInterval);
        
        for(; i < intervals.size(); i++)
            v.push_back(intervals[i]);
        
        return v;
    }
};
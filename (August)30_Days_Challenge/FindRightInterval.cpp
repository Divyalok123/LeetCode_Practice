/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3438/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        
        int i;
        for(i = 0; i < intervals.size(); i++)
        {
            m[intervals[i][0]] = i;
        }
        
        vector<int> ans(intervals.size(), -1);
        for(int j = 0; j < intervals.size(); j++)
        {
            auto pointer = m.lower_bound(intervals[j][1]);
            if(pointer != m.end()) ans[j] = pointer->second;
        }
        
        return ans;
    }
};
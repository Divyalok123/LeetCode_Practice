/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3425/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        
        int prev = intervals[0][1], count = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < prev) {
                count++;
                if(intervals[i][1] < prev) prev = intervals[i][1];
            } else prev = intervals[i][1];
        }
        
        return count;
    }
};
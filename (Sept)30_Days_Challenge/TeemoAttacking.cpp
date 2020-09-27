/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3473/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeseries, int duration) {
        int n = timeseries.size();
        if(n == 0)
            return 0;
        int ans = 0, i = 0;
        while(i < n-1)
        {
            if(timeseries[i+1]-timeseries[i] < duration)
                ans += timeseries[i+1]-timeseries[i];
            else 
                ans += duration;
            i++;
        }
        
        ans += duration;
        return ans;
    }
};
/*
https://leetcode.com/problems/best-sightseeing-pair/submissions/
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0); return 0;}();
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = values[1] + values[0] - 1;
        int n = values.size(), maxval = values[1]+1 > values[0] ? values[1] + 1 : values[0];
        for(int i = 2; i < n; i++) {
            int newval = values[i]-i + maxval;
            if(ans < newval)
                ans = newval;
            
            if(maxval < values[i]+i)
                maxval = values[i]+i;
        }
        
        return ans;
    }
};
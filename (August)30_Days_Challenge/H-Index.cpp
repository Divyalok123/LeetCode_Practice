/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3420/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        if(c.size() == 0) return 0;
        sort(c.begin(), c.end());
        int ans = 1;
        for(int i = c.size()-1; i >= 0; i--) {
            if (c[i] < c.size() - i)
            { return c.size()-i-1; }
            ans++;
        }
        return ans-1;
    }
};
/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3559/
*/

#include <iostream>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60);
        int ans = 0;
        
        for(auto& t: time) {
            int x = t%60;
            if(x == 0) ans += v[0];
            else ans += v[60-x];
            v[x]++;
        }
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60);
        for(auto& t: time)
            v[t%60]++;
        
        int ans = 0;
        ans += (v[0]-1)*v[0]/2;
        for(int i = 1; i < 30; i++) {
            ans += v[i]*v[60-i];
        }
        ans += (v[30]-1)*v[30]/2;
        return ans;
    }
};

/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3631/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, INT_MAX);
        
        int ind = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == c) ind = i;
            if(ind != -1)
                ans[i] = i-ind;
        }
        
        ind = -1;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == c) ind = i;
            if(ind != -1 && ind-i < ans[i])
                ans[i] = ind-i;
        }
        return ans;
   }
};
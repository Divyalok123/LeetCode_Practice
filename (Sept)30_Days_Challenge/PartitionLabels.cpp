/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size() == 0) return {};
        vector<int> v(26);
        vector<int> ans;
        int i;
        for(i = 0; i < S.size(); i++)
            v[S[i]-'a'] = i;
        
        int maxim = -1, last = 0;
        for(i = 0; i < S.size(); i++)
        {
            maxim = max(maxim, v[S[i]-'a']);
            if(maxim == i)
                ans.push_back(maxim-last+1), last = i+1;
        }
        return ans;
    }
};
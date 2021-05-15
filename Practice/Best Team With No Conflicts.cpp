/*
https://leetcode.com/problems/best-team-with-no-conflicts/
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

// DP O(n^2)
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<array<int, 2>> vec(n);
        
        for(int i = 0; i < n; i++)
            vec[i] = {ages[i], scores[i]};
        
        sort(vec.begin(), vec.end());
        
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++)
            dp[i] = vec[i][1];
        
        for(int i = 0; i < n; i++) {
            int val = vec[i][1];
            for(int j = 0; j < i; j++) {
                if(vec[j][1] <= val)
                    dp[i] = max(dp[i], dp[j] + val);
            }
        }
        
        int ans = 0;
        for(int& i: dp)
            if(i > ans)
                ans = i;
        
        return ans;
    }
};
/*
https://leetcode.com/problems/longest-arithmetic-subsequence/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Improvement
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int dp[n][1001];
        memset(dp, 0, sizeof(dp));
        unordered_map<int, int> inds; //only taking uniques
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            for(const auto& j: inds) {
                int diff = A[i]-j.first+500;
                dp[i][diff] = dp[j.second][diff] + 1;

                if(dp[i][diff] > ans)
                    ans = dp[i][diff];
            }
            inds[A[i]] = i;
        }
        
        return ans + 1;
    }
};

// bottom-up dp
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int dp[n][1001];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                int diff = A[i]-A[j]+500;
                if(dp[j][diff] + 1 > dp[i][diff])
                    dp[i][diff] = dp[j][diff] + 1;

                if(dp[i][diff] > ans)
                    ans = dp[i][diff];
            }
        }
        
        return ans + 1;
    }
};
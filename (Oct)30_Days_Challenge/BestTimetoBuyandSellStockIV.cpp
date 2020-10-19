/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3499/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/* Solution 3 */


/* Solution 2 */


/* Solution 1 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        
        int n = prices.size();
        if(k >= n/2) {
            int ans = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i-1])
                    ans += prices[i]-prices[i-1];
            }
            return ans;
        }
        
        vector<int> dp(k+1, 0), minv(k+1, INT_MIN);
        for(auto& a: prices) {
            for(int j = 1; j <= k; j++) {
                minv[j] = max(minv[j], dp[j-1]-a);
                dp[j] = max(dp[j], minv[j] + a);
            }
        }
        
        return dp[k];
    }
};

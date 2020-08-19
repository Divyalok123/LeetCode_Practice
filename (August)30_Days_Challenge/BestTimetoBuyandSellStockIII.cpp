/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3426/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Solution 3*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int dp[3];
        int minv[3];
        fill(minv, minv + 3, prices[0]);
        memset(dp, 0, sizeof(dp)); //memset doesn't always work properly so use fill/fill_n or put elements iteratively
        for (int i = 1; i < prices.size(); i++)
        {
            for (int k = 1; k <= 2; k++)
            {
                minv[k] = min(minv[k], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - minv[k]);
            }
        }

        return dp[2];
    }
};

/* Solition 2 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int** dp = new int*[3];
        for(int i = 0; i < 3; i++)
        {
            dp[i] = new int[prices.size()];
            for(int j = 0; j < prices.size(); j++)
                dp[i][j] = 0;
        }
         
        int minv[3];
        for(int i = 0; i < 3; i++)
            minv[i] = prices[0];
        
        for(int j = 1; j < prices.size(); j++) {
            for(int i = 1; i <= 2; i++)
            { 
                minv[i] = min(minv[i], prices[j-1] - dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]-minv[i]);
            }
        }
        return dp[2][prices.size()-1];
    }
};

/* Solition 1 (TLE) */ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int** dp = new int*[3], minv;
        for(int i = 0; i < 3; i++)
        {
            dp[i] = new int[prices.size()];
            for(int j = 0; j < prices.size(); j++)
                dp[i][j] = 0;
        }
         
        for(int j = 1; j < prices.size(); j++) {
            for(int i = 1; i <= 2; i++)
            { 
                minv = prices[0];
                for(int k = 1; k <= j; k++)
                    minv = min(minv, prices[k] - dp[i-1][k-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]-minv);
            }
        }
        return dp[2][prices.size()-1];
    }
};
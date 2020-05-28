#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Solution 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
        {
            return 0;
        }
        
        int dp[10000][2];
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(0, dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        for(int i = 2; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            
        }
        
        return dp[n-1][0];
    }
};


//Solution 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
        {
            return 0;
        }
        
        int buy[10000] = {0};
        int sell[10000] = {0};
        
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++)
        {
            buy[i] = max(buy[i-1], (i-2 >= 0 ? sell[i-2] : 0) - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);                         
        }
        
        return sell[n-1];
    }
};

//Solution 3 (Best)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cool = 0, hold = INT_MIN, sell = 0;
        for(int i = 0; i < n; i++)
        {
            hold = max(hold, cool - prices[i]);
            cool = sell;
            sell = max(sell, hold + prices[i]);
        }
        return max(cool, sell);
    }
};
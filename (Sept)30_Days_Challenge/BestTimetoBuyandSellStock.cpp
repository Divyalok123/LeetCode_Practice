/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3464/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        if(prices.size() == 1) return prices[0] < prices[1] ? prices[1]-prices[0] : 0;
        
        int maxans = 0, currans = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            maxans = max(maxans, prices[i]-currans);
            if(prices[i] < currans) currans = prices[i];
        }
        return maxans;
    }
};
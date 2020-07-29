/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int hold = INT_MIN, sell = 0, cool = 0;
        for (int i = 0; i < n; i++)
        {
            hold = max(hold, cool - prices[i]);
            cool = sell;
            sell = max(sell, hold + prices[i]);
        }
        return max(cool, sell);
    }
};

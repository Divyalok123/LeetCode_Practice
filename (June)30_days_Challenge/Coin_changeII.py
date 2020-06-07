# You are given coins of different denominations and a total amount of money. 
# Write a function to compute the number of combinations that make up that amount. 
# You may assume that you have infinite number of each kind of coin.

from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        size = len(coins)
        dp = [[0 for _ in range(size+1)] for _ in range(amount+1)]
        
        for i in range(size+1):
            dp[0][i] = 1
        
        for i in range(1, amount+1):
            for j in range(1, size+1):
                a = dp[i][j-1]
                b = 0
                if(coins[j-1] <= i):
                    b = dp[i-coins[j-1]][j]
                dp[i][j] = a + b
        return dp[amount][size]
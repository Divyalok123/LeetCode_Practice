# Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
# Si % Sj = 0 or Sj % Si = 0.
# If there are multiple solutions, return any subset is fine.

from typing import List

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        size = len(nums)
        if(size == 0 or size == 1):
            return nums
        nums.sort()
        dp = [1 for _ in range(size)]
        
        maxEl = -1
        for i in range(size):
            for j in range(i-1, -1, -1):
                if(nums[i]%nums[j] == 0):
                    dp[i] = max(dp[i], dp[j]+1)
            maxEl = max(maxEl, dp[i])
            
        output = []
        pivot = -1
        for i in range(size-1, -1, -1):
            if(dp[i] == maxEl and (pivot == -1 or pivot%nums[i] == 0)):
                if(pivot == -1):
                    pivot = nums[i]
                output.append(nums[i])
                maxEl-=1
                
        return output

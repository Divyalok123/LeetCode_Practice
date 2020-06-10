# Given a sorted array and a target value, return the index if the target is found.
# If not, return the index where it would be if it were inserted in order.
# You may assume no duplicates in the array.

from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        s = len(nums)
        l = 0
        r = s-1
        while(l <= r):
            m = (l+r)//2
            if(nums[m] == target):
                return m
            elif(nums[m] < target):
                l = m+1
            else:
                r = m-1
        return l
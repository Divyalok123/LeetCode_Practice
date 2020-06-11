# Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
# Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
# Note: You are not suppose to use the library's sort function for this problem.

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        size, i, nz = len(nums), 0, 0
        nt = size-1
        while(i <= nt):
            if(nums[i] == 0):
                nums[i], nums[nz] = nums[nz], nums[i]
                nz += 1
                i += 1
            elif(nums[i] == 1):
                i += 1
            else:
                nums[i], nums[nt] = nums[nt], nums[i]
                nt -= 1

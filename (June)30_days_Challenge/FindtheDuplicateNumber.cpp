// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist.
// Assume that there is only one duplicate number, find the duplicate one.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/* ---- Solution 2 (Floyd's Tortoise and Hare) ---- */
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int tort = nums[0];
        int hare = nums[0];

        tort = nums[tort];
        hare = nums[nums[hare]];

        while (tort != hare)
        {
            tort = nums[tort];
            hare = nums[nums[hare]];
        }

        tort = nums[0];
        while (tort != hare)
        {
            tort = nums[tort];
            hare = nums[hare];
        }

        return hare;
    }
};

/* ---- Solution 1 (Binary Search) ---- */
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int size = nums.size(), start = 1, end = size - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int count = 0;
            for (int i = 0; i < size; i++)
                if (nums[i] <= mid)
                    count++;
            if (count > mid)
            {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return start;
    }
};

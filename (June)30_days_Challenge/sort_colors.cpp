// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: You are not suppose to use the library's sort function for this problem.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int size = nums.size(), i = 0, nz = 0;
        int nt = size - 1;

        while (i <= nt)
        {
            if (nums[i] == 0)
            {
                int temp = nums[nz];
                nums[nz++] = nums[i];
                nums[i] = temp;
                i++;
            }

            else if (nums[i] == 1)
                i++;
            else
            {
                int temp = nums[nt];
                nums[nt--] = nums[i];
                nums[i] = temp;
            }
        }
    }
};
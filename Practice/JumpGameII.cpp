/*
https://leetcode.com/problems/jump-game-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/** Method 2 **/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int count = 0, prev = 0, curr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > prev)
                count++, prev = curr;
            curr = max(curr, nums[i]+i);
        }
        return count;   
    }
};

/** Method 1 **/
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;

        int count = 0, i = 0;
        while (i < nums.size())
        {
            count++;
            if (nums[i] + i >= nums.size() - 1)
                return count;

            int maxval = 0;
            int maxind = i;
            for (int j = i + 1; j < nums.size() && j <= nums[i] + i; j++)
            {
                if (nums[j] + j > maxval)
                {
                    maxval = nums[j] + j;
                    maxind = j;
                }

                if (nums[j] + j >= nums.size() - 1)
                    break;
            }

            if (maxind == i)
                return 0;
            i = maxind;
        }

        return count;
    }
};
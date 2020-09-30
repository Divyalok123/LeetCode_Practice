/*
https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/558/week-5-september-29th-september-30th/3478/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;

        int i = 0;
        while (i < nums.size())
        {
            if ((nums[i] <= 0) || (nums[i] > nums.size()) || (i != nums[i] - 1 && nums[nums[i] - 1] == nums[i]))
            {
                int temp = nums.back();
                nums[nums.size() - 1] = nums[i];
                nums[i] = temp;
                nums.pop_back();
            }
            else
            {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
                if (nums[i] == i + 1)
                    i++;
            }
        }

        for (i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;

        return nums.size() + 1;
    }
};
/*Given an unsorted integer array, find the smallest missing positive integer.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/* O(n) */
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            if (nums[i] == i + 1 || nums[i] > nums.size() || nums[i] <= 0)
                continue;
            swap(nums[i], nums[a - 1]);
            if (nums[i] != nums[a - 1])
                i--;
        }

        int i;
        for (i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;
        return i + 1;
    }
};

/* O(nlogn) */
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;
        sort(nums.begin(), nums.end());

        int i = 0;
        if (nums[i] > 0 && nums[i] != 1)
            return 1;
        while ((i < nums.size() && nums[i] < 0) || (i < nums.size() - 1 && nums[i + 1] - nums[i] <= 1))
        {
            if (i < nums.size() - 1 && nums[i] < 0 && nums[i + 1] > 0 && nums[i + 1] != 1)
                return 1;
            i++;
        }
        if (i == 0)
        {
            if (nums[i] != 1)
                return 1;
            else
                return 2;
        }
        if (i == nums.size())
        {
            if (nums[nums.size() - 1] < 0)
                return 1;
            else
                return nums[nums.size() - 1] + 1;
        }
        if (i == nums.size() - 1)
        {
            if (nums[i - 1] < 0 && nums[i] != 1)
                return 1;
            return nums[nums.size() - 1] + 1;
        }
        return nums[i] + 1;
    }
};
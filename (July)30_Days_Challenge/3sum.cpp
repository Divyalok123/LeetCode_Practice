/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        int size = nums.size();

        if (size <= 2)
            return output;

        // cout << "entering for" << endl;
        for (int i = 0; i < size - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int x = i + 1;
            int y = size - 1;
            // cout << "entering while" << endl;
            while (x < y)
            {
                int t = nums[x] + nums[y] + nums[i];

                if (t == 0)
                {
                    // cout << "before if" << endl;
                    output.push_back({nums[i], nums[x], nums[y]});
                    // cout << "pushed" << endl;
                    while (x < size - 1 && nums[x] == nums[x + 1])
                        x++;
                    while (y > 0 && nums[y] == nums[y - 1])
                        y--;
                    x++;
                    y--;
                }
                else if (t < 0)
                {
                    // cout << "before else if" << endl;
                    x++;
                }
                else
                {
                    // cout << "before else" << endl;
                    y--;
                }
            }
        }

        return output;
    }
};
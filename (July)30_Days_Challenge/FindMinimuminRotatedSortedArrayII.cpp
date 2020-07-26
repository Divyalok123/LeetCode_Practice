/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
---The array may contain duplicates.---
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

/* Solution 3 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int s = 0, m, e = nums.size() - 1;

        while (s < e)
        {
            if (nums[s] < nums[e])
                return nums[s];

            m = s + (e - s) / 2;
            if (nums[m] < nums[s])
                e = m;
            else if (nums[m] > nums[s])
                s = m + 1;
            else
                s++;
        }
        return nums[s];
    }
};

/* Solution 2 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
                return nums[i];
        return nums[0];
    }
};

/* Solution 1 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/* Solution 3 */
class Solution
{
public:
    int part(vector<int> &nums, int l, int h)
    {

        int piv = rand() % (h - l + 1) + l;
        swap(nums[h], nums[piv]);
        int i = l, j = l;
        while (j < h)
        {
            if (nums[j] <= nums[h])
            {
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }

        swap(nums[h], nums[i]);
        return i;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return nums[0];

        srand(time(0));
        int i = 0, j = n - 1;
        while (i < j)
        {
            int p = part(nums, i, j);
            if (p == n - k)
                break;
            else if (p < n - k)
                i = p + 1;
            else
                j = p - 1;
        }

        return nums[n - k];
    }
};

/* Solution 2 */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return nums[0];
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[n - k];
    }
};

/* Solution 1 */
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 1)
            return nums[0];

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        for (int i = k; i < n; i++)
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }

        return pq.top();
    }
};
/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3546/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == k)
            return {*max_element(nums.begin(), nums.end())};

        vector<int> ans(n - k + 1);
        vector<int> l(n), r(n);
        int lmax = 0, rmax = 0;
        l[0] = nums[0], r[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            l[i] = (i % k) ? max(l[i - 1], nums[i]) : nums[i];
            r[n - i - 1] = ((n - i) % k) ? max(r[n - i], nums[n - i - 1]) : nums[n - i - 1];
        }

        for (int i = 0; i <= n - k; i++)
        {
            ans[i] = max(r[i], l[i + k - 1]);
        }

        return ans;
    }
};

/* Solution 1 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == k)
            return {*max_element(nums.begin(), nums.end())};

        if (k == 1)
            return nums;

        vector<int> ans(n - k + 1);
        deque<int> d;
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            while (!d.empty() && d.front() < i - k + 1)
                d.pop_front();

            while (!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();

            d.push_back(i);

            if (i >= k - 1)
                ans[a++] = nums[d.front()];
        }

        return ans;
    }
};
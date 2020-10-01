/*
https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = requests.size(), m = nums.size();
        vector<int> count(m);
        for (int i = 0; i < n; i++)
        {
            count[requests[i][0]]++;
            if (requests[i][1] + 1 < m)
                count[requests[i][1] + 1]--;
        }

        for (int i = 0; i < m-1; i++)
            count[i+1] += count[i];

        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < m; i++)
            res = (res + nums[i] * count[i]) % 1000000007;

        return res;
    }
};
/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

/* Solution 3 */
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {0};
        vector<int> ans(n), bucket(105);

        for (int &a : nums)
            bucket[a]++;

        for (int i = 1; i < 105; i++)
            bucket[i] += bucket[i - 1];

        for (int i = 0; i < nums.size(); i++)
            ans[i] = nums[i] == 0 ? 0 : bucket[nums[i] - 1];

        return ans;
    }
};

/* Solution 2 */
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {0};
        map<int, int> mm;
        for (int i = 0; i < nums.size(); i++)
            mm[nums[i]]++;

        int l = 0, temp;
        map<int, int>::iterator it = mm.begin();
        while (it != mm.end())
        {
            temp = it->second;
            it->second = l;
            it++;
            l += temp;
        }

        for (int i = 0; i < nums.size(); i++)
            nums[i] = mm[nums[i]];
        return nums;
    }
};

/* Solution 1 */
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {0};
        vector<int> newnum = nums;
        unordered_map<int, int> umap;
        sort(nums.begin(), nums.end());

        int l = 0;
        for (int i = 0; i < nums.size(); i++)
            umap[nums[i]] = (i == 0 || (nums[i] != nums[i - 1])) ? l : umap[nums[i - 1]], l++;

        for (int i = 0; i < newnum.size(); i++)
            newnum[i] = umap[newnum[i]];
        return newnum;
    }
};
/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3446/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

//solution 2
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        if (k == 0 || n <= 1)
            return false;

        long num, id;
        map<long, long> mapp;
        for (int i = 0; i < n; i++)
        {
            if (i > k)
                mapp.erase(((long)nums[i - k - 1] - INT_MIN) / ((long)t + 1));
            num = (long)nums[i] - INT_MIN;
            id = num / ((long)t + 1);

            if (mapp.count(id) || (mapp.count(id - 1) && (((long)nums[i] - mapp[id - 1]) <= t)) || (mapp.count(id + 1) && ((mapp[id + 1] - (long)nums[i]) <= t)))
                return true;

            mapp[id] = nums[i];
        }
        return false;
    }
};

//solution 1
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        if (k == 0 || n <= 1)
            return false;

        set<long> s;
        for (int i = 0; i < n; i++)
        {
            auto bot = s.lower_bound((long)nums[i] - t);
            // auto top = s.upper_bound((long)nums[i]+t);

            if (bot != s.end() && (*bot <= (long)nums[i] + t))
                return true;
            // if(top != s.begin())
            // {
            //     top = prev(top);
            //     if(*top >= (long)nums[i]) return true;
            // }

            s.insert((long)nums[i]);
            if (i >= k)
                s.erase((long)nums[i - k]);
        }

        return false;
    }
};
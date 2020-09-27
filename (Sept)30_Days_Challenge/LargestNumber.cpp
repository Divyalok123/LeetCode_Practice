/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3472/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/** Solution 2 **/
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (nums.size() == 0)
            return "";

        sort(nums.begin(), nums.end(), [](int a, int b) {
            long long left = 10, right = 10;

            while (left <= b)
                left *= 10;

            while (right <= a)
                right *= 10;

            left *= a;
            left += b;

            right *= b;
            right += a;

            return left > right;
        });

        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); i++)
            v[i] = to_string(nums[i]);

        string ans;
        for (auto &a : v)
        {
            ans += a;
        }

        if (ans[0] == '0')
            return "0";
        return ans;
    }
};

/** solution 1 **/
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (nums.size() == 0)
            return "";

        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); i++)
            v[i] = to_string(nums[i]);

        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string ans;
        for (auto &a : v)
        {
            ans += a;
        }

        // if (ans[0] == '0')
        // {
        //     int i = 0;
        //     while (ans[i] == '0')
        //         i++;
        //     ans = ans.substr(i);
        // }
        // if (ans == "")
        //     ans = "0";

        if (ans[0] == '0')
            return "0";
        return ans;
    }
};
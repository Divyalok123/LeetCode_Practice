/*
    Given a non-empty array of integers, return the k most frequent elements.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//solution 1
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mapp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mapp[nums[i]]++;

        vector<vector<int>> b(n + 1);
        for (auto a : mapp)
            b[a.second].push_back(a.first);

        vector<int> output;

        for (int i = n; i >= 0; i--)
        {
            if (output.size() == k)
                break;

            for (int a : b[i])
            {
                output.push_back(a);
                if (output.size() == k)
                    break;
            }
        }
        return output;
    }
};

//solution 0
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mapp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mapp[nums[i]]++;

        vector<pair<int, int>> v;
        for (auto a : mapp)
            v.push_back({a.second, a.first});

        nth_element(v.begin(), v.begin() + k, v.end(), [&](pair<int, int> &x, pair<int, int> &y) {
            return x.first > y.first;
        });

        vector<int> output;
        for (int i = 0; i < k; i++)
            output.push_back(v[i].second);

        return output;
    }
};
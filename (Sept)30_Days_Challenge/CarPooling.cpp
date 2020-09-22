/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3467/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

/* --- Solution 2 --- */
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();
        if (n == 0)
            return true;
        if (n == 1)
            return trips[0][0] <= capacity;

        vector<int> v(1001);
        for (int i = 0; i < n; i++)
        {
            v[trips[i][1]] += trips[i][0];
            v[trips[i][2]] -= trips[i][0];
        }

        int count = 0;
        for (int i = 0; i < 1001; i++)
        {
            count += v[i];
            if (count > capacity)
                return false;
        }

        return true;
    }
};

/* --- Solution 1 --- */
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();
        if (n == 0)
            return true;
        if (n == 1)
            return trips[0][0] <= capacity;

        sort(trips.begin(), trips.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1] || (a[1] == b[1] && a[2] < b[2]);
        });

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int count = 0;
        for (int i = 0; i < trips.size(); i++)
        {
            while (!pq.empty() && (pq.top().first <= trips[i][1]))
                count -= pq.top().second, pq.pop();
            pq.push({trips[i][2], trips[i][0]});
            count += trips[i][0];
            if (count > capacity)
                return false;
        }

        return true;
    }
};
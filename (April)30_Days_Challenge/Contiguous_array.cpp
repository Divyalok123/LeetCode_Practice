// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &a)
    {
        unordered_map<int, int> mp;
        int sm = 0, mx = 0;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                a[i] = -1;
            sm += a[i];
            if (sm == 0)
                mx = i + 1;
            if (mp.find(sm) != mp.end())
            {
                mx = max(mx, i - mp[sm]);
            }
            else
            {
                mp[sm] = i;
            }
        }
        return mx;
    }
};
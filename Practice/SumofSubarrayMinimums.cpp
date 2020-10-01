/*
https://leetcode.com/problems/sum-of-subarray-minimums/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

//--------(1)---------//
class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        int sum = 0, n = A.size();
        if (n == 1)
            return A[0];
        stack<pair<int, int>> s, ss;
        vector<int> v(n), sv(n);
        for (int i = 0; i < n; i++)
            sv[i] = n - i;

        pair<int, int> p;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().second > A[i])
                s.pop();
            v[i] = s.empty() ? i + 1 : i - s.top().first;
            s.push({i, A[i]});

            while (!ss.empty() && ss.top().second > A[i])
            {
                p = ss.top(), ss.pop();
                sv[p.first] = i - p.first;
            }
            ss.push({i, A[i]});
        }

        for (int i = 0; i < n; i++)
        {
            sum = (sum + A[i] * v[i] * sv[i]) % 1000000007;
        }

        return sum;
    }
};
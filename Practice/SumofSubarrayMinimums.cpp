/*
https://leetcode.com/problems/sum-of-subarray-minimums/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

//--------(2)---------//
#define MOD 1000000007
class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        int sum = 0, n = A.size(), ans = 0;
        if (n == 1)
            return A[0];
        stack<int> s;
        s.push(-1);
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            while ((s.top() != -1) && (A[s.top()] >= A[i]))
                s.pop();
            dp[i + 1] = (dp[s.top() + 1] + (i - s.top()) * A[i]) % MOD;
            s.push(i);
            ans += dp[i + 1];
            ans %= MOD;
        }

        return ans;
    }
};

//--------(1)---------//
class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        int sum = 0, n = A.size();
        if (n == 1)
            return A[0];
        vector<int> v1(n), v2(n);
        {
            stack<int> s1, s2;

            for (int i = 0; i < n; i++)
            {
                while (!s1.empty() && A[s1.top()] > A[i])
                    s1.pop();
                v1[i] = s1.empty() ? i + 1 : i - s1.top();
                s1.push(i);
            }

            for (int i = n - 1; i >= 0; i--)
            {
                while (!s2.empty() && A[s2.top()] >= A[i])
                    s2.pop();
                v2[i] = s2.empty() ? n - i : s2.top() - i;
                s2.push(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + A[i] * v1[i] * v2[i]) % 1000000007;
        return ans;
    }
};
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;

/* --- solution 3 --- */
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX - 10000);

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sqrt(i); j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

/* --- solution 2 (lagrange) (fastest) --- */
class Solution
{
public:
    bool isperfect(int n)
    {
        return (sqrt(n) - floor(sqrt(n))) == 0;
    }

    //can be represented as a sum of 4 squares
    int numSquares(int n)
    {

        //handling 1
        if (isperfect(n))
            return 1;

        // handling 2
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (isperfect(n - i * i))
                return 2;
        }

        //handling 4
        while ((n & 3) == 0)
        {
            n >>= 2;
        }

        if ((n & 7) == 7)
            return 4;

        //else 3
        return 3;
    }
};

/* --- solution 1 (A not so good solution) --- */
class Solution
{
public:
    vector<int> sqrs;
    bool flag = false;
    bool isperfect(int n)
    {
        return (sqrt(n) - floor(sqrt(n))) == 0;
    }

    vector<int> store;

    int numSquares(int n)
    {
        if (n == 1)
            return 1;

        if (isperfect(n))
            return 1;

        if (!flag)
        {
            for (int i = 1; i <= sqrt(n); i++)
                sqrs.push_back(i * i);
            flag = true;
            store.resize(n + 5, -1);
        }

        if (n < 0)
            return INT_MAX - 10000;

        if (n >= 0 && store[n] != -1)
            return store[n];

        int minim = INT_MAX - 10000;
        for (int i = 0; i < sqrs.size(); i++)
        {
            int ans = 1 + numSquares(n - sqrs[i]);
            if (ans < minim)
                minim = ans;
        }
        store[n] = minim;
        return minim;
    }
};
// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

#include <iostream>
#include <algorithm>
using namespace std;

/* ------------- Catalan Number Formula ---------- */
class Solution {
public:
    int numTrees(int n) {
        return round(tgamma(2*n+1)/(tgamma(n+2)*tgamma(n+1)));
    }
};

/* ------------- DP ---------------- */
class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        int *memo = new int[n + 1];
        for (int i = 0; i <= n; i++)
            memo[i] = 0;

        memo[0] = 1;
        memo[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int ans = 0;
            for (int j = 0; j < i; j++)
            {
                ans += memo[i - j - 1] * memo[j];
            }
            memo[i] = ans;
        }

        return memo[n];
    }
};

/* ------------- Memo -------------- */
class Solution
{
public:
    int helper(int n, long long *output)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        if (n == 4)
            return 14;
        if (output[n] != -1)
            return output[n];
        int ans = 0;
        int i = n - 1;
        int j = 0;
        while (i >= 0)
        {
            ans += helper(i, output) * helper(j, output);
            i--;
            j++;
        }
        output[n] = ans;
        return ans;
    }

    int numTrees(int n)
    {
        long long *memo = new long long[n + 1];
        for (int i = 0; i <= n; i++)
            memo[i] = -1;
        return helper(n, memo);
    }
};
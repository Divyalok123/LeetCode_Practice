/*
https://leetcode.com/problems/3sum-with-multiplicity/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD 1000000007

// Solution 2
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        vector<int> v(101);
        for (int &i : arr)
            v[i]++;

        int ans = 0, lim = min(target, 100);
        for (int i = 0; i <= lim; i++)
        {
            int t = target - i;

            if (t - i >= 0 && t - i <= 100)
            {
                if (3 * i == target)
                    ans = (ans + 1ll * v[i] * (v[i] - 1) * (v[i] - 2) / 6) % MOD;

                else
                    ans = (ans + 1ll * v[t - i] * v[i] * (v[i] - 1) / 2) % MOD;
            }

            for (int j = i + 1; j <= lim; j++)
            {
                if (j == t - j)
                {
                    ans = (ans + 1ll * v[i] * v[j] * (v[j] - 1) / 2) % MOD;
                    break;
                }

                else if (t - j > j && t - j <= 100)
                    ans = (ans + 1ll * v[i] * v[j] * v[t - j]) % MOD;
            }

            v[i] = 0;
        }

        return ans;
    }
};

// Solution 1 (O(n^2))
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int ans = 0, n = arr.size(), t, temp;

        sort(arr.begin(), arr.end());

        while (n > 0 && arr[n - 1] > target)
            n--;

        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            t = target - arr[i];
            if (arr[l] == arr[r])
            {
                if (2 * arr[l] == t)
                {
                    ans = (ans + 1ll * (r - l) * (r - l + 1) / 2) % MOD;
                }
                continue;
            }

            while (l < r)
            {
                if (arr[l] + arr[r] == t)
                {
                    if (arr[l] == arr[r])
                    {
                        ans = (ans + 1ll * (r - l) * (r - l + 1) / 2) % MOD;
                        break;
                    }

                    int ll = arr[l], rr = arr[r], countl = 0, countr = 0;
                    while (l < r && arr[l] == ll)
                        countl++, l++;
                    while (l <= r && arr[r] == rr)
                        countr++, r--;

                    ans = (ans + 1ll * countl * countr) % MOD;
                }

                else if (arr[l] + arr[r] < t)
                    l++;
                else
                    r--;
            }
        }

        return ans;
    }
};
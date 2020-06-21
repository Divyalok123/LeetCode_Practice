#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/* ----------------- Solution 2 ----------------------- */
class Solution
{
    int factof[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

public:
    string getPermutation(int n, int k)
    {

        string s, ans;
        for (int i = 1; i <= n; i++)
            s.push_back(i + '0');

        while (s.size() != 0)
        {
            int x = ceil((float)k / factof[n - 1]);
            ans.push_back(s[x - 1]);
            s.erase(x - 1, 1);
            k -= (k / factof[n - 1]) * factof[n - 1];
            if (k == 0)
            {
                reverse(s.begin(), s.end());
                ans += s;
                break;
            }
            n--;
        }

        return ans;
    }
};

/* ----------------- Solution 1 (STL) ----------------- */
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string s;
        for (int i = 1; i <= n; i++)
        {
            s.push_back(i + '0');
        }

        sort(s.begin(), s.end());

        for (int i = 0; i < k - 1; i++)
        {
            next_permutation(s.begin(), s.end());
        }

        return s;
    }
};
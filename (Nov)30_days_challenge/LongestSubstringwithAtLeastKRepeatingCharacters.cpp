/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3544/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* Solution 2 */


/* Solution 1 */
class Solution
{
public:
    int helper(string &s, int k, int l, int r)
    {
        if (r < l || r < k)
            return 0;

        int arr[26] = {0};

        for (int i = l; i < r; i++)
            arr[s[i] - 'a']++;

        for (int m = l; m < r; m++)
        {
            if (arr[s[m] - 'a'] < k)
            {

                int frst = helper(s, k, l, m);
                while (m < r && arr[s[m] - 'a'] < k)
                    m++;

                return max(frst, helper(s, k, m, r));
            }
        }

        return r - l;
    }

    int longestSubstring(string s, int k)
    {
        return helper(s, k, 0, s.size());
    }
};

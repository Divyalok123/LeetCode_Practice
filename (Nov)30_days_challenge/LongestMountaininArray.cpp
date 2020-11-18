/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3533/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 1 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        if (A.size() <= 2)
            return 0;
        int ans = 0;
        int curr1, curr2, i = 0, n = A.size();
        while (i < n)
        {
            curr1 = 1, curr2 = 0;
            while (i < n - 1 && A[i] < A[i + 1])
                i++, curr1++;
            if (curr1 == 1)
            {
                i++;
                continue;
            }
            while (i < n - 1 && A[i] > A[i + 1])
                i++, curr2++;
            if (curr2 == 0)
            {
                i++;
                continue;
            }
            ans = max(ans, curr1 + curr2);
        }

        return ans;
    }
};
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        int ans = 0;
        while (i < n)
        {
            int sum = nums[i];
            i++;
            while (i < n && nums[i - 1] < nums[i])
                sum += nums[i++];

            ans = max(ans, sum);
        }

        return ans;
    }
};
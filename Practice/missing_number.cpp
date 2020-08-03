/* https://leetcode.com/problems/missing-number/ */

#include <iostream>
#include <vector>
using namespace std;

/* way 2 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (auto a : nums)
            sum += a;

        sum -= (n * (n + 1)) / 2;
        return -1 * sum;
    }
};

/* way 1 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == i || nums[i] == nums.size())
                continue;
            swap(nums[i], nums[nums[i]]);
            if (nums[i] < nums.size() && nums[i] != nums[nums[i]])
                i--;
        }

        int i;
        for (i = 0; i < nums.size(); i++)
            if (nums[i] != i)
                return i;
        return i;
    }
};
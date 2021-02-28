#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = 0, sum2 = 0;
        int n = nums1.size(), m = nums2.size();

        for (int &i : nums1)
            sum1 += i;
        for (int &i : nums2)
            sum2 += i;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int diff = abs(sum1 - sum2);
        if (diff == 0)
            return 0;

        int op = 0;
        if (sum1 > sum2)
        {

            int i = n - 1, j = 0;
            while (diff)
            {
                int diff1 = i >= 0 ? nums1[i] - 1 : 0, diff2 = j < m ? 6 - nums2[j] : 0;

                if (!diff1 && !diff2)
                    return -1;

                if (diff1 >= diff || diff2 >= diff)
                {
                    op++;
                    break;
                }
                else if (diff1 + diff2 >= diff)
                {
                    op += 2;
                    break;
                }
                else
                {
                    if (diff1 > diff2)
                    {
                        diff -= diff1;
                        i--;
                    }
                    else
                    {
                        diff -= diff2;
                        j++;
                    }
                    op++;
                }
            }
        }
        else
        {

            int i = 0, j = m - 1;
            while (diff)
            {
                int diff1 = i < n ? 6 - nums1[i] : 0, diff2 = j >= 0 ? nums2[j] - 1 : 0;

                if (!diff1 && !diff2)
                    return -1;

                if (diff1 >= diff || diff2 >= diff)
                {
                    op++;
                    break;
                }
                else if (diff1 + diff2 >= diff)
                {
                    op += 2;
                    break;
                }
                else
                {
                    if (diff1 > diff2)
                    {
                        diff -= diff1;
                        i++;
                    }
                    else
                    {
                        diff -= diff2;
                        j--;
                    }
                    op++;
                }
            }
        }

        return op;
    }
};
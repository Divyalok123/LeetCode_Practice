#include <iostream>
#include <vector>
#include <algorithm>

namespace Solution
{
    std::vector<int> maximizeXor(std::vector<int> &nums, std::vector<std::pair<int, int>> const &queries)
    {
        const int q = queries.size();
        std::vector<int> ans(q, -1);
        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int i = 0; i < q; ++i)
        {
            int const x = queries[i].first, m = queries[i].second;

            if (m < nums[0])
                continue;

            auto end = upper_bound(nums.begin(), nums.end(), m);
            auto start = nums.begin();

            int cur = 0;

            int const MaxBit = 1 << sizeof(int) * CHAR_BIT - 2;
            for (int bit = MaxBit; start != prev(end); bit >>= 1)
            {

                if (x & bit)
                {
                    if (!(*start & bit))
                        end = lower_bound(start, end, cur | bit);
                    else
                        cur |= bit;
                }
                else
                {
                    if (/*start < end &&*/ *prev(end) & bit) {
                        cur |= bit;
                        start = lower_bound(start, end, cur);
                    }
                }

                ans[i] = *start ^ x;
            }
        }
        return ans;
    }
}
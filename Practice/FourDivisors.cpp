/*
https://leetcode.com/problems/four-divisors/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;
        int sum, count;
        for (auto &num : nums)
        {
            sum = num + 1;
            count = 2;

            if (num < 6)
                continue;

            if (num % 2 == 0)
            {
                if (num == 8)
                {
                    ans += 6 + sum;
                    continue;
                }

                int t = num;
                t /= 2;
                if (t % 2 == 0)
                    continue;

                if (num / 2 != 2)
                {
                    sum += 2 + num / 2;
                    count += 2;
                }
                else
                {
                    count++;
                }
            }

            for (int i = 3; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    if (num / i != i)
                    {
                        sum += i + num / i;
                        count += 2;
                    }
                    else
                    {
                        count++;
                    }
                }
            }

            if (count == 4)
                ans += sum;
        }
        return ans;
    }
};
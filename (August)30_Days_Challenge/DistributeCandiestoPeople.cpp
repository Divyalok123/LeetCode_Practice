/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3427/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    int val(int a, int d, int n)
    {
        return ((n) * (2 * a + (n - 1) * d)) / 2;
    }

public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        if (candies == 0)
            return {};
        int n = 0;
        while ((n * n + n) <= 2 * candies)
            n++;
        n--;
        int rem, a, b, x;
        rem = candies - (n * n + n) / 2;
        a = n / num_people;
        b = n - a * num_people;
        x = b;
        vector<int> v(num_people, 0);
        for (int i = 0; i < num_people; i++)
        {
            v[i] = val(i + 1, num_people, a + (b-- > 0 ? 1 : 0));
        }
        v[x] += rem;
        return v;
    }
};
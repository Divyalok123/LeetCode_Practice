/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3465/
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
void generate()
{
    int num = 12, n, val, left, right;
    while (log10(num) < 9)
    {
        v.push_back(num);
        n = num;
        num = 0;
        val = log10(n);
        left = n / pow(10, val);
        right = n % 10;
        if ((left = 9 - val) && right == 9)
        {
            for (int i = 1; i <= val + 2; i++)
            {
                num += i * pow(10, val - i + 2);
            }
        }
        else
        {
            for (int i = 0; i <= val; i++)
                num += ((n % 10 + 1) * pow(10, i)), n /= 10;
        }
    }
}

bool isdone = false;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        if (!isdone)
            generate(), isdone = true;

        vector<int> ans;
        int i = 0;
        while (i < v.size() && v[i] < low)
            i++;

        while (i < v.size() && v[i] <= high)
            ans.push_back(v[i++]);

        return ans;
    }
};
/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3462/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class node
{
public:
    node *bits[2];
    node()
    {
        for (int i = 0; i < 2; i++)
            bits[i] = NULL;
    }
};
class Solution
{
    node *root = new node();

    void add(node *nn, int n)
    {
        int v;
        for (int i = 31; i >= 0; i--)
        {
            v = (n >> i) & 1;
            if (nn->bits[v] == NULL)
                nn->bits[v] = new node();
            nn = nn->bits[v];
        }
    }

    int query(node *nn, int n)
    {
        int res = 0, j;
        for (int i = 31; i >= 0 && nn; i--)
        {
            j = (n >> i) & 1;
            if (nn->bits[j ^ 1])
            {
                res <<= 1;
                res |= 1;
                nn = nn->bits[j ^ 1];
            }
            else
            {
                res <<= 1;
                res |= 0;
                nn = nn->bits[j];
            }
        }
        return res;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, query(this->root, nums[i]));
            add(this->root, nums[i]);
        }
        return ans;
    }
};
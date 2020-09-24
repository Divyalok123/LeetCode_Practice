/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3470/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ----- Method 3 ----- */ //another way to write method 2
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int i, ans = 0, gassum = 0, costsum = 0, diffsum = 0;
        for (i = 0; i < gas.size(); i++)
        {
            gassum += gas[i];
            costsum += cost[i];

            diffsum += gas[i] - cost[i];

            if (diffsum < 0)
            {
                ans = i + 1;
                diffsum = 0;
            }
        }

        return costsum <= gassum ? ans : -1;
    }
};

/* ----- Method 2 ----- */
//observing that if we can't reach k from i then we can't reach k from anything between k & i hence we jump to i+1 and continue
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int i, j;

        for (i = 0; i < gas.size(); i += j)
        {
            int sum = 0;
            for (j = 1; j <= gas.size(); j++)
            {
                int k = (i + j - 1) % gas.size();
                sum += gas[k] - cost[k];

                if (sum < 0)
                    break;
            }

            if (j > gas.size())
                return i;
        }

        return -1;
    }
};

/* ----- Method 1 ----- */ //simplest method
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ans = -1;
        for (int i = 0; i < gas.size(); i++)
        {
            int val = gas[i] - cost[i];
            int j = -1;
            if (val >= 0)
                for (j = i + 1; j < i + gas.size(); j++)
                {
                    val += gas[j % gas.size()];
                    val -= cost[j % gas.size()];

                    if (val < 0)
                        break;
                }

            if (j == i + gas.size())
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};
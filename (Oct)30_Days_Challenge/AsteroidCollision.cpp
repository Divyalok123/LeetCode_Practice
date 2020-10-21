/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3502/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        if (n <= 1)
            return asteroids;

        vector<int> ans;
        int i = 0;
        while (i < n)
        {
            if (asteroids[i] > 0)
                ans.push_back(asteroids[i++]);
            else
            {
                int j = ans.size() - 1;
                while (j >= 0)
                {
                    if (ans[j] < 0)
                        break;
                    else if (ans[j] < abs(asteroids[i]))
                    {
                        j--;
                        ans.pop_back();
                    }
                    else if (ans[j] > abs(asteroids[i]))
                        break;
                    else if (ans[j] == abs(asteroids[i]))
                    {
                        ans.pop_back();
                        break;
                    }
                }

                if (j < 0 || (ans[j] < 0))
                    ans.push_back(asteroids[i]);
                i++;
            }
        }

        return ans;
    }
};
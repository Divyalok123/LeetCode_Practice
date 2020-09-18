/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3463/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string cc = "NESW";
    bool isRobotBounded(string instructions)
    {
        int ic = 0;
        char c = cc[ic];
        pair<int, int> p = {0, 0};

        for (int i = 0; i < instructions.size(); i++)
        {
            if (instructions[i] == 'G')
            {
                if (c == 'N')
                    p.second++;
                else if (c == 'E')
                    p.first++;
                else if (c == 'S')
                    p.second--;
                else if (c == 'W')
                    p.first--;
            }
            else if (instructions[i] == 'L')
                ic = (ic + 3) % 4, c = cc[ic];
            else
                ic = (ic + 5) % 4, c = cc[ic];
        }

        return p == make_pair(0, 0) || ic > 0;
    }
};

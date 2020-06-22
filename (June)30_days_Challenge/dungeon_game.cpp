// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> answer(n, vector<int>(m));
        /*--- We can also use the given array for the Dp too ---*/
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    answer[i][j] = dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
                else if (i == n - 1)
                    answer[i][j] = max((answer[i][j + 1] - dungeon[i][j]), 1);
                else if (j == m - 1)
                    answer[i][j] = max((answer[i + 1][j] - dungeon[i][j]), 1);
                else
                    answer[i][j] = max(1, min(answer[i][j + 1], answer[i + 1][j]) - dungeon[i][j]);
            }
        }

        return answer[0][0];
    }
};
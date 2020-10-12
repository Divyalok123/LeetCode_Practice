/*
https://leetcode.com/problems/game-of-life/
*/

#include <iostream>
#include <vector>
using namespace std;

#define f first
#define s second
class Solution
{
    int n, m, a, b;
    pair<int, int> moves[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}};
    bool notfine(int i, int j)
    {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        n = board.size();
        if (n == 0)
            return;
        m = board[0].size();
        int count;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count = 0;
                for (int k = 0; k < 8; k++)
                {
                    a = i + moves[k].f;
                    b = j + moves[k].s;

                    if (notfine(a, b))
                        continue;

                    if (board[a][b] & 1)
                        count++;
                }

                if (board[i][j] == 1)
                {
                    if ((count == 2) || (count == 3))
                    {
                        cout << "here" << endl;
                        board[i][j] += 2;
                    }
                }
                else
                {
                    if (count == 3)
                        board[i][j] += 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] >>= 1;
    }
};
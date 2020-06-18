// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//--------------------------- Solution 2-----------------------

/*  In the below solution we don't need to use a queue and run BFS.
    We can just traverse the matrix and replace elements. So we will be save the space of queue for each function call*/

//----------------------------------------------------- Solution 1 -----------------------------------------------------------
class Solution
{
public:
    void reset(bool **v, int n, int m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                v[i][j] = false;
    }

    void bfs(vector<vector<char>> &board, int i, int j, int n, int m, char a, char b, bool **visited)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();

            int x = t.first;
            int y = t.second;
            board[x][y] = b;
            if (x - 1 >= 0 && board[x - 1][y] == a && !visited[x - 1][y])
            {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if (x + 1 < n && board[x + 1][y] == a && !visited[x + 1][y])
            {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }

            if (y - 1 >= 0 && board[x][y - 1] == a && !visited[x][y - 1])
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }

            if (y + 1 < m && board[x][y + 1] == a && !visited[x][y + 1])
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }
    }

    void gen(vector<vector<char>> &board, int i, int j, int n, int m, char a, char b, bool **v)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        v[i][j] = true;
        while (!q.empty())
        {
            pair<int, int> t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if (board[x][y] == a)
                board[x][y] = b;

            if (x - 1 >= 0 && !v[x - 1][y])
            {
                q.push({x - 1, y});
                v[x - 1][y] = true;
            }

            if (x + 1 < n && !v[x + 1][y])
            {
                q.push({x + 1, y});
                v[x + 1][y] = true;
            }

            if (y - 1 >= 0 && !v[x][y - 1])
            {
                q.push({x, y - 1});
                v[x][y - 1] = true;
            }

            if (y + 1 < m && !v[x][y + 1])
            {
                q.push({x, y + 1});
                v[x][y + 1] = true;
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;

        bool **v = new bool *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            v[i] = new bool[m + 1];
        }

        reset(v, n, m);

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                bfs(board, i, 0, n, m, 'O', '1', v);

            if (board[i][m - 1] == 'O')
                bfs(board, i, m - 1, n, m, 'O', '1', v);
        }

        for (int i = 1; i < m - 1; i++)
        {
            if (board[0][i] == 'O')
                bfs(board, 0, i, n, m, 'O', '1', v);
            if (board[n - 1][i] == 'O')
                bfs(board, n - 1, i, n, m, 'O', '1', v);
        }

        reset(v, n, m);
        gen(board, 0, 0, n, m, 'O', 'X', v);

        reset(v, n, m);
        gen(board, 0, 0, n, m, '1', 'O', v);
    }
};
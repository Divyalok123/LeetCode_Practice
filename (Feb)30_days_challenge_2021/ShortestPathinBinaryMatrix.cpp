/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3638/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

// Solution 3 (A* search)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;        

        int moves[8][2] = {{0,1}, {0,-1}, {1,0}, {1,1}, {1,-1}, {-1,-1},{-1, 0}, {-1,1}};
        
        using ppi = pair<pair<int, int>, pair<int, int>>;
        class cmp {
            public:
            bool operator()(ppi const& a, ppi const& b){return a.ss.ff > b.ss.ff;};
        };
        
        priority_queue<ppi, vector<ppi>, cmp> pq;
        pq.push(mp(mp(0,0), mp(2*n, 1)));
        
        while(pq.size()) {
            ppi p = pq.top();
            pq.pop();
            
            int val = p.ss.ss;
            int pi = p.ff.ff, pj = p.ff.ss;
            
            if(pi == n-1 && pj == n-1) return val;

            for(int i = 0; i < 8; i++) {
                int newi = pi + moves[i][0];
                int newj = pj + moves[i][1];

                if(newi>=0 && newi<n && newj>=0 && newj<n) {
                    if(!grid[newi][newj] || grid[newi][newj] > val + 1) {
                        grid[newi][newj] = val + 1;
                        int heu = val + min((n-newi+1), (n-newj+1));
                        pq.push(mp(mp(newi, newj), mp(heu, val+1)));
                    }
                }
            }
        }
        
        return -1;
    }
    
};

// Solution 2 (Normal BFS)
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        int moves[8][2] = {{0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;
        int ans = 0;
        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> p = q.front();
                q.pop();

                int pi = p.ff, pj = p.ss;
                if (pi == n - 1 && pj == n - 1)
                    return ans + 1;

                for (int i = 0; i < 8; i++)
                {
                    int newi = pi + moves[i][0];
                    int newj = pj + moves[i][1];

                    if (newi >= 0 && newi < n && newj >= 0 && newj < n && !vis[newi][newj] && !grid[newi][newj])
                    {
                        vis[newi][newj] = 1;
                        q.push(mp(newi, newj));
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};

// Solution 1 (Dijkstra)
#define mp make_pair
#define ff first
#define ss second

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        using ppi = pair<int, pair<int, int>>;

        if (n == 1)
            return grid[0][0] == 0 ? 1 : -1;

        if (grid[0][0] == 1)
            return -1;
        class cmp
        {
        public:
            bool operator()(ppi &a, ppi &b)
            {
                return a.first > b.first;
            }
        };

        priority_queue<ppi, vector<ppi>, cmp> pq;
        int moves[8][2] = {{0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        pq.push(mp(1, mp(0, 0)));
        while (pq.size())
        {
            auto top = pq.top();
            pq.pop();
            for (int i = 0; i < 8; i++)
            {
                int newi = top.ss.ff + moves[i][0];
                int newj = top.ss.ss + moves[i][1];

                if (newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 0 && dist[newi][newj] > top.ff + 1)
                {
                    dist[newi][newj] = top.ff + 1;
                    if (newi == n - 1 && newj == n - 1)
                        return dist[newi][newj];
                    pq.push(mp(top.ff + 1, mp(newi, newj)));
                }
            }
        }

        return -1;
    }
};
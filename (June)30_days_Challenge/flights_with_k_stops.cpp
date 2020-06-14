// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops.
// If there is no such route, output -1.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//DFS (no sefl cycle so no need for visited check)
class Solution
{
public:
    void dfs(int s, int d, int k, int cost, unordered_map<int, vector<pair<int, int>>> &mapp, int &ans)
    {
        if (s == d)
        {
            ans = cost;
            return;
        }
        if (k == 0)
            return;

        for (auto p : mapp[s])
        {
            if (p.second + cost > ans)
                continue;
            dfs(p.first, d, k - 1, cost + p.second, mapp, ans);
        }
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> mapp;
        for (auto i : flights)
            mapp[i[0]].emplace_back(i[1], i[2]);

        int ans = INT_MAX;
        dfs(src, dst, k + 1, 0, mapp, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};

//BFS
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> mapp;

        for (auto f : flights)
            mapp[f[0]].emplace_back(f[1], f[2]);

        int ans = INT_MAX;
        queue<pair<int, int>> q;
        q.push({src, 0});

        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> p = q.front();
                q.pop();

                if (p.first == dst)
                {
                    ans = min(ans, p.second);
                }

                for (auto x : mapp[p.first])
                {
                    if (x.second + p.second > ans)
                        continue;
                    q.push(make_pair(x.first, x.second + p.second));
                }
            }
            if (steps > k)
                break;
            steps++;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

//BF
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int INF = 1e6;
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));
        dp[0][src] = 0;

        for (int i = 1; i <= k + 1; i++)
        {
            dp[i][src] = 0;
            for (auto &a : flights)
            {
                dp[i][a[1]] = min(dp[i][a[1]], dp[i - 1][a[0]] + a[2]);
            }
        }
        return (dp[k + 1][dst] == INF) ? -1 : dp[k + 1][dst];
    }
};
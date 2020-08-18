/*
https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*DFS*/
class Solution
{
public:
    void dfs(vector<int> &v, int n, int k, int i)
    {
        if (n == 0)
        {
            v.push_back(i);
            return;
        }
        int val = i % 10;
        for (int j = 0; j <= 9; j++)
            if (abs(val - j) == k)
                dfs(v, n - 1, k, i * 10 + j);
    }

    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> v;
        if (N == 1)
        {
            v.push_back(0);
        }

        for (int i = 1; i <= 9; i++)
            dfs(v, N - 1, K, i);
        return v;
    }
};

/*BFS*/
class Solution
{
public:
    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        if (N == 1)
        {
            v.push_back(0);
            return v;
        }
        queue<int> q;
        for (auto a : v)
            q.push(a);
        int i;
        for (i = 2; i <= N; i++)
        {
            int s = q.size();
            while (s--)
            {
                int x = q.front();
                q.pop();

                for (int i = 0; i <= 9; i++)
                {
                    if (abs(x % 10 - i) == K)
                    {
                        q.push(x * 10 + i);
                    }
                }
            }
        }
        v.resize(q.size());
        i = 0;
        while (!q.empty())
            v[i++] = q.front(), q.pop();
        return v;
    }
};